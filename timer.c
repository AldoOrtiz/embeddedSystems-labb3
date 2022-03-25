#include "timer.h"

#include <avr/io.h>

int timeMillis = 0;
int prev = 0;

void timer0() {
    // Fast PWM-mod
    TCCR0A &= ~(1 << COM0A0);
    TCCR0A |= (1 << COM0A1);

    TCCR0A |= (1 << WGM00) | (1 << WGM01);
    TCCR0B &= ~(1 << WGM02);

    // Prescaler = 64 Table 15-9.
    TCCR0B |= (1 << CS00) | (1 << CS01);
    TCCR0B &= ~(1 << CS02);
}

void timer2() {
    // A Register 1024 prescaler
    TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);

    // CTC Table 22-9.
    TCCR2A &= ~(1 << WGM20);
    TCCR2A |= (1 << WGM21);
    TCCR2B &= ~(1 << WGM22);

    // clear 0C2A on compare match
    TCCR2A |= (1 << COM2A0) | (1 << COM2A1);

    // Interrupts
    TIMSK2 |= (1 << OCIE2A);

    // 16000000/1024*0.001 -1 since it starts at index 0, to get ~10ms = 100Hz
    OCR2A = 155;
}