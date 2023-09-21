/*!
 * \file    main.c
 * \author  your name (you@domain.com)
 * \brief   brief description of what program does
 * \version 0.1
 * \date    2023-06-26
 */

#define  F_CPU 2000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "serialF0.h"

#define DELAY_BASE 250
#define DELAY_INCR 50

/*!
 * \brief  main starting point of the program.
 * \return int (with embedded this will never happen)
 */
int main()
{
    /////////////////////
    //  Initialization //
    /////////////////////

    // Initialize the stream to be able to print with the UART
    init_stream(F_CPU);
    // Enable global interrupts
    sei();

    // Set pin 0 on port C as output
    PORTC.DIRSET = PIN0_bm;

    int sequence_number = 0;


    ///////////////////////////////
    //  Enter endless while-loop //
    ///////////////////////////////
    printf("Entering never ending while loop now.\n");
    while (1) {
        sequence_number++;

        printf("Say hello sequence number is %d\n", sequence_number);

        // Toggle pin 0 of port C (from high to low or low to high)
        PORTC.OUTTGL = PIN0_bm;
        _delay_ms(DELAY_BASE + (DELAY_INCR * sequence_number));
    }
}
