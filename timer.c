#include "timer.h"

#include <avr/io.h>

void timer_init() {
    // ...
}

void timer2() {
    // A Register
    TCCR2B |= (1 << CS20);
    TCCR2B |= (1 << CS21);
    TCCR2B |= (1 << CS22);
    TCCR2B &= ~(1 << WGM22);

    // CTC Table 22-9. B Register
    TCCR2A &= ~(1 << WGM20);
    TCCR2A |= (1 << WGM21);

    // Set 0C2A on compare match
    TCCR2A |= (1 << COM2A0);
    TCCR2A |= (1 << COM2A1);

    // Set top counter to 16000000/1024*0.001 -1 since it starts at index 0, to get ~1ms
    OCR2A = 15;
}