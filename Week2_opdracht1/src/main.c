/**
 * @file    main.c
 * @author  nico verduin
 * @brief   example program to get started (i.e. blinky)
 * @version 1.0
 * @date    11-4-2023
 *
 */
#define  F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief  mainline of the program
 * @return nothing as we never get there
 */
int main(void) {
    // Set pin 3 of port D as an output
    PORTD.DIRSET = PIN3_bm;

    while (1) {
        // Set pin 0 of port C high, LED is on
        PORTD.OUTSET = PIN3_bm;
        _delay_ms(100);

        // Set pin 0 of port C low, LED is off
        PORTD.OUTCLR = PIN3_bm;
        _delay_ms(100);
    }
}
