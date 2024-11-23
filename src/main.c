#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "tusb.h"

#include "pico_led.h"


#ifndef WAIT_FOR_USB
#define WAIT_FOR_USB 1
#endif

int main() {
    stdio_init_all();

    pico_led_init();

#if WAIT_FOR_USB == 1
    while(tud_cdc_connected() == false) { sleep_ms(1); }
    sleep_ms(100);
#endif

    printf("INIT DONE\n");

    uint8_t a = 0;
    while (true) {
        pico_set_led(true);
        sleep_ms(250);
        pico_set_led(false);
        sleep_ms(250);
        printf("Loop %hu\n", ++a);
    }
}
