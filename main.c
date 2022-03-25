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

// global variabel
volatile uint8_t ADC_val = 0;

ISR(ADC_vect) {
    ADC_val = ADCH;
}

// Stard ADC
ISR(TIMER2_COMPA_vect) {
    ADCSRA |= (1 << ADSC);
    OCR0A = ADC_val;
}

int main() {
    DDRD &= ~(1 << PB3);
    DDRD &= ~(1 << PB0);
    DDRD &= ~(1 << PD2);

    LED_init();
    uart_init();
    timer2();
    timer0();

    // ADC
    DDRC &= ~(1 << PC0);
    ADMUX |= (1 << ADLAR) | (1 << REFS0);
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1);
    ADCSRA |= (1 << ADEN) | (1 << ADIE);

    sei();

    while (1) {
        buttonDebounce();
        // ADCSRA |= (1 << ADSC);
        if (bit_is_set(TIFR2, OCF2A)) {  // millis
            timeMillis++;
            TIFR2 = (1 << OCF2A);
        }
    }
}

// ISR(ADC_vect) {
//     ADCvalue = ADCH;
// }
