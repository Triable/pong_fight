/**
 * @file    main.c
 * @author  nico verduin
 * @brief   example program to get started (i.e. blinky)
 * @version 1.0
 * @date    11-4-2023
 *
 */
#define  F_CPU 2000000UL
#define N 16

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief  mainline of the program
 * @return nothing as we never get there
 */
int main(void) {
    PORTD.DIRSET = PIN0_bm + PIN1_bm + PIN2_bm + PIN3_bm;

    int led_output = 0;

    while (1) {
        // Set pin 0 of port C high, LED is on
        PORTD.OUT = led_output;

        _delay_ms(125);

        // Set pin 0 of port C low, LED is off
        led_output++;
        if (led_output >= N) {
            led_output = 0;
        }
    }
}
