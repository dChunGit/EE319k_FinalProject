// dac.c
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 8/25/2014 
// Last Modified: 3/6/2015 
// Section 1-2pm     TA: Wooseok Lee
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void)
{/*
	SYSCTL_RCGCGPIO_R |= 0x04; //Set up outputs on Port E
	while((SYSCTL_RCGCGPIO_R&0x04) != 0x04){};
	GPIO_PORTC_DIR_R |= 0xF0;
	GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTC_AFSEL_R &= ~0xF0;
	GPIO_PORTC_DR8R_R |= 0xF0; //8mA
	*/
	SYSCTL_RCGCGPIO_R |= 0x04; //Set up outputs on Port E
	while((SYSCTL_RCGCGPIO_R&0x04) != 0x04){};
	GPIO_PORTC_DIR_R |= 0xF0;
	GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTC_AFSEL_R &= ~0xF0;
	GPIO_PORTC_DR8R_R |= 0xF0; //8mA
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(uint32_t data)
{
	GPIO_PORTC_DATA_R = (data)<<4;
}
