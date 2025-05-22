
#include "pico/stdlib.h"
#include "st7789/st7789.h"

int main() {
    stdio_init_all();
    st7789_init();

    while (1) {
        st7789_fill(0xF800); // vermelho
        sleep_ms(1000);
        st7789_fill(0x07E0); // verde
        sleep_ms(1000);
        st7789_fill(0x001F); // azul
        sleep_ms(1000);
    }
}
