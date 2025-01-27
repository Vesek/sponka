#ifndef MODES_H
#define MODES_H

#include "ch32v003fun.h"

typedef struct {
    uint16_t frametime;      // Represents the frame time in milliseconds
    uint32_t (*get_pixel)(void); // Pointer to the function associated with the frame
} mode_t;

void init_modes(void);
uint32_t rainbow_get_pixel(void);
uint32_t flashbang_get_pixel(void);
uint32_t black_get_pixel(void);

static mode_t sponka_modes[] = {{100, rainbow_get_pixel}, {500, rainbow_get_pixel}, {10000, flashbang_get_pixel}};

#endif
