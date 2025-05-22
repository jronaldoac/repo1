
#ifndef ST7789_H
#define ST7789_H

#include "pico/stdlib.h"

#define ST7789_WIDTH  240
#define ST7789_HEIGHT 320

void st7789_init(void);
void st7789_fill(uint16_t color);
void st7789_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
void st7789_set_address_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

#endif
