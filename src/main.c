#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "drawing.h"


int main(void)
{
	volatile int * HEXa_ctrl_ptr = (int *)0xFF200020;	// Pointer to HEX0-HEX3 address
	volatile int * HEXb_ctrl_ptr = (int *)0xFF200030;	// Pointer to HEX4-HEX5 address
	volatile int * KEY_ctrl_ptr = (int *)0xFF200050;	// Pointer to KEY0 address
	volatile int * SW_ctrl_ptr = (int *)0xFF200040;		// Pointer to SW address
	volatile int * EDGECAPTURE_ctrl_ptr = (int *)0xFF20005C; // Pointer to edge capture bit
	volatile int * LEDR_ctrl_ptr = (int *)0xFF200000;	// Pointer to LEDR address

	int secondA = 0, minuteA = 0, hourA = 0, secondB = 0, minuteB = 0, hourB = 0;
	
	// Initialize pixel buffer variables
	volatile int * pixel_ctrl_ptr = (int *)0xFF203020;
	pixel_buffer_start = *pixel_ctrl_ptr;
	clear_screen();
	
	*LEDR_ctrl_ptr = 0b1111111111;
	
	// First time input
	*HEXa_ctrl_ptr = 0x00000000;
	*HEXb_ctrl_ptr = 0x00000000;

	// Flag indicates that there is a number in the timer other than 0
	int flag = 0;
	
	/*
	Switch 1: sets the number of seconds on the alarm clock
	Switch 2: sets the number of minutes on the alarm clock
	Switch 3: sets the number of hours on the alarm clock
	Key 1: increase the number of seconds/minutes/hours by 1
	Key 2: increase the number of seconds/minutes/hours by 5
	*/

	while (1)
	{
		// Set the number of seconds
		if ((*SW_ctrl_ptr) == 1)
		{
			// Increase the number of seconds by 1
			if ((*EDGECAPTURE_ctrl_ptr) == 1)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b1;
				secondA = secondA + 1;
			}
			// Increase the number of seconds by 5
			else if ((*EDGECAPTURE_ctrl_ptr) == 2)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b10;
				secondA = secondA + 5;
			}

			// Loop number of seconds
			if (secondA >= 60)
				secondA = 0;
			flag = 1;
		}
		// Set the number of minutes
		else if ((*SW_ctrl_ptr) == 2)
		{
			// Increase the number of minutes by 1
			if ((*EDGECAPTURE_ctrl_ptr) == 1)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b1;
				minuteA = minuteA + 1;
			}
			// Increase the number of minutes by 5
			else if ((*EDGECAPTURE_ctrl_ptr) == 2)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b10;
				minuteA = minuteA + 5;
			}

			// Loop number of minutes
			if (minuteA >= 60)
				minuteA = 0;
			flag = 1;
		}
		// Set the number of hours
		else if ((*SW_ctrl_ptr) == 4)
		{
			// Increase the number of hours by 1
			if ((*EDGECAPTURE_ctrl_ptr) == 1)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b1;
				hourA = hourA + 1;
			} 
			// Increase the number of hours by 5
			else if ((*EDGECAPTURE_ctrl_ptr) == 2)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b10;
				hourA = hourA + 5;
			}

			// Loop number of hours
			if (hourA >= 24)
				hourA = 0;
			flag = 1;
		}
	
		// Done setting the first time
		if ((*EDGECAPTURE_ctrl_ptr) == 8)
			break;
		
		if (((*EDGECAPTURE_ctrl_ptr)==1) && ((*SW_ctrl_ptr)==0))
			*EDGECAPTURE_ctrl_ptr = 0b1;
		
		if (((*EDGECAPTURE_ctrl_ptr)==2) && ((*SW_ctrl_ptr)==0))
			*EDGECAPTURE_ctrl_ptr = 0b10;

	}



	return 0;
}