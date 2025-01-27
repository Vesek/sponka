#include "ch32v003fun.h"
#include "lib_rand.h"

#define MAX_VALUE 0x20

void init_modes(void){
   	seed(0x12345678);
}

uint32_t rainbow_get_pixel(void){
    return ((rand()%MAX_VALUE) | ((rand()%MAX_VALUE) << 8) | ((rand()%MAX_VALUE) << 16));
}

uint32_t flashbang_get_pixel(void){
    return 0x00FFFFFF;
}

uint32_t black_get_pixel(void){
    return 0;
}
