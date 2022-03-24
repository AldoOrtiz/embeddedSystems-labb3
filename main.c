#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "button.h"
#include "led.h"
#include "serial.h"
#include "stdbool.h"
#include "timer.h"

int main() {
    DDRD &= ~(1 << PB3);
    DDRD &= ~(1 << PB0);
    DDRD &= ~(1 << PD2);

    LED_init();
    uart_init();
    timer2();

    while (1) {
        buttonDebounce();

        if (bit_is_set(TIFR2, OCF2A)) {  // millis
            timeMillis++;
            TIFR2 = (1 << OCF2A);
        }
    }
}

// ISR(ADC_vect) {
//     ADCvalue = ADCH;
// }
