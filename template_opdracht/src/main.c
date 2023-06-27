/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-26
 * 
 */

#define  F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief main starting point of the program.
 * @return int (with embedded this will never happen
 */
int main() {

  PORTC.DIRSET = PIN0_bm;       // bit 0 port C is set, it is an output

  // endless loop
  while (1) {

    PORTC.OUTTGL = PIN0_bm;     // toggle bit 0 port C
    _delay_ms (100);
  }
}