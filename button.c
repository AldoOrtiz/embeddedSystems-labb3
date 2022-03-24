#include "button.h"

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "stdbool.h"
#include "timer.h"

int buttonDebounce() {
    if (bit_is_set(PIND, PD2)) {
        if (prev == 0) {
            prev = timeMillis;
            printf("released\r\n");
        }
    } else if (prev != 0 && (timeMillis - prev) > 10) {  // interruption management
        prev = 0;
        printf("pushed\r\n");
    }
}
