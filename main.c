#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdlib.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int main() {
    DDRD &= ~(1 << PB3);
    DDRD &= ~(1 << PB0);
    DDRD &= ~(1 << PD2);

    LED_init();
    uart_init();
    // timer_init();
    while (1) {
        if (bit_is_set(PIND, PD2)) {
            printf("test");
        }
    }
}

// ISR(ADC_vect) {
//     ADCvalue = ADCH;
// }
