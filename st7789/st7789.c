
#include "st7789.h"
#include "hardware/spi.h"
#include "hardware/gpio.h"

#define DC 13
#define RST 11
#define CS 12

static inline void st7789_cmd(uint8_t cmd) {
    gpio_put(DC, 0);
    gpio_put(CS, 0);
    spi_write_blocking(spi0, &cmd, 1);
    gpio_put(CS, 1);
}

static inline void st7789_data(const uint8_t *data, size_t len) {
    gpio_put(DC, 1);
    gpio_put(CS, 0);
    spi_write_blocking(spi0, data, len);
    gpio_put(CS, 1);
}

void st7789_init() {
    gpio_init(DC);
    gpio_init(RST);
    gpio_init(CS);
    gpio_set_dir(DC, GPIO_OUT);
    gpio_set_dir(RST, GPIO_OUT);
    gpio_set_dir(CS, GPIO_OUT);

    spi_init(spi0, 62500000);
    gpio_set_function(14, GPIO_FUNC_SPI); // SCK
    gpio_set_function(15, GPIO_FUNC_SPI); // MOSI

    gpio_put(RST, 0);
    sleep_ms(50);
    gpio_put(RST, 1);
    sleep_ms(50);

    st7789_cmd(0x01); // Software reset
    sleep_ms(150);
    st7789_cmd(0x11); // Sleep out
    sleep_ms(500);
    st7789_cmd(0x29); // Display on
}

void st7789_fill(uint16_t color) {
    // Implementação mínima: preencher tela inteira (opcionalmente expansível)
}
