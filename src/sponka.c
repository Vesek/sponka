#include "ch32v003fun.h"
#include <stdbool.h>

#define WS2812DMA_IMPLEMENTATION
#define WSGRB // For SK6805-EC15
#define N_LEDS 5
#include "ws2812b_dma_spi_led_driver.h"

#include "ch32v003_GPIO_branchless.h"

#include "modes.h"

#define N_MODES (sizeof(sponka_modes) / sizeof((sponka_modes)[0]))

bool skip_frametime = false;
uint8_t mode = 0;

void EXTI7_0_IRQHandler( void ) __attribute__((interrupt));
void EXTI7_0_IRQHandler( void )
{
    skip_frametime = true;
    mode = (mode + 1) % N_MODES;
    EXTI->INTFR = 0xffffffff;
}

// Callbacks that you must implement.
uint32_t WS2812BLEDCallback( int ledno )
{
    return sponka_modes[mode].get_pixel();
}

int main()
{
	SystemInit();

	// Init button
	GPIO_port_enable(GPIO_port_D);
	GPIO_pinMode(GPIOv_from_PORT_PIN(GPIO_port_D, 7), GPIO_pinMode_I_pullUp, GPIO_Speed_In);

	RCC->APB2PCENR |= RCC_AFIOEN;

	// assign pin 7 interrupt from portD (0b11) to EXTI channel 2
	AFIO->EXTICR |= (uint32_t)(0b11 << (2*7));

	// enable line2 interrupt event
	EXTI->INTENR |= EXTI_Line7;
	EXTI->FTENR |= EXTI_Line7;

	NVIC_EnableIRQ( EXTI7_0_IRQn );

	WS2812BDMAInit( );

	uint32_t targend = SysTick->CNT + Ticks_from_Ms(sponka_modes[mode].frametime);
	while (true){
	    if (skip_frametime || (((int32_t)( SysTick->CNT - targend )) > 0)){
			targend = SysTick->CNT + Ticks_from_Ms(sponka_modes[mode].frametime);

            skip_frametime = false;

            WS2812BDMAStart( N_LEDS );

            while( WS2812BLEDInUse );
		}
	}

	return 0;
}
