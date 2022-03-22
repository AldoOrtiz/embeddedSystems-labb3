#include "button.h"

#include <avr/io.h>

void buttonDebounce() {
    DDRD &= ~(1 << PD2);
}