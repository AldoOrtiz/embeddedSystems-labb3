#include "led.h"

#include <avr/io.h>
#include <stdint.h>

void LED_init() {
    DDRD |= (1 << PD6);
}

uint8_t simple_ramp() {
    return 1;
}
