/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "tusb.h"

#include "dummy_lib.h"

#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#endif

#ifndef WAIT_FOR_USB
#define WAIT_FOR_USB 1
#endif

int main() {
    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

#if WAIT_FOR_USB == 1
    while(tud_cdc_connected() == false) { sleep_ms(1); }
    sleep_ms(100);
#endif

    printf("INIT DONE\n");

    uint8_t a = 0;
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        a = add(a, 1);
        printf("Loop %hu\n", a);
    }
}
