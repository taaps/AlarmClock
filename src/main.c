#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "drawing.h"
#include "bit_organizer.h"


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

	// First time input
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
	
		// Done setting the first time, exit out of this loop
		if ((*EDGECAPTURE_ctrl_ptr) == 8)
			break;
		
		if (((*EDGECAPTURE_ctrl_ptr)==1) && ((*SW_ctrl_ptr)==0))
			*EDGECAPTURE_ctrl_ptr = 0b1;
		
		if (((*EDGECAPTURE_ctrl_ptr)==2) && ((*SW_ctrl_ptr)==0))
			*EDGECAPTURE_ctrl_ptr = 0b10;

		// Store bit values for second, minute and hour variables at appropriate addresses
		if (flag)
		{
			assignSecondBitA(secondA, HEXa_ctrl_ptr, 0x000000FF);
			assignSecondBitB(secondA, HEXa_ctrl_ptr, 0x0000FF00);
			assignMinuteBitA(minuteA, HEXa_ctrl_ptr, 0x00FF0000);
			assignMinuteBitB(minuteA, HEXa_ctrl_ptr, 0xFF000000);
			assignHourBitA(hourA, HEXb_ctrl_ptr, 0x000000FF);
			assignHourBitB(hourA, HEXb_ctrl_ptr, 0x0000FF00);
		}
	}

	// Second time input
	*EDGECAPTURE_ctrl_ptr = 0b1000;
	*HEXa_ctrl_ptr = 0x00000000;
	*HEXb_ctrl_ptr = 0x00000000;
	
	while (true)
	{
		if ((*SW_ctrl_ptr) == 1)
		{
			// Increase the number of seconds by 1
			if ((*EDGECAPTURE_ctrl_ptr) == 1)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b1;
				secondB = secondB + 1;
			}
			// Increase the number of seconds by 5
			else if ((*EDGECAPTURE_ctrl_ptr) == 2)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b10;
				secondB = secondB + 5;
			}

			// Loop number of seconds
			if (secondB >= 60)
				secondB = 0;
		}
		
		else if ((*SW_ctrl_ptr) == 2)
		{
			// Increase the number of minutes by 1
			if ((*EDGECAPTURE_ctrl_ptr) == 1)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b1;
				minuteB = minuteB + 1;
			}
			// Increase the number of minutes by 5
			else if ((*EDGECAPTURE_ctrl_ptr) == 2)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b10;
				minuteB = minuteB + 5;
			}

			// Loop number of minutes
			if (minuteB >= 60)
				minuteB = 0;
		}
		
		else if ((*SW_ctrl_ptr) == 4)
		{
			// Increase the number of hours by 1
			if ((*EDGECAPTURE_ctrl_ptr) == 1)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b1;
				hourB = hourB + 1;
			}
			// Increase the number of hours by 5
			else if ((*EDGECAPTURE_ctrl_ptr) == 2)
			{
				// Reset edgecapture bit
				*EDGECAPTURE_ctrl_ptr = 0b10;
				hourB = hourB + 5;
			}

			// Loop number of hours
			if (hourB >= 24)
				hourB = 0;
		}
	
		// Done setting the first time, exit out of this loop
		if ((*EDGECAPTURE_ctrl_ptr) == 8)
			break;

		if (((*EDGECAPTURE_ctrl_ptr)==1) && ((*SW_ctrl_ptr)==0))
			*EDGECAPTURE_ctrl_ptr = 0b1;
		
		if (((*EDGECAPTURE_ctrl_ptr)==2) && ((*SW_ctrl_ptr)==0))
			*EDGECAPTURE_ctrl_ptr = 0b10;

		assignSecondBitA(secondB, HEXa_ctrl_ptr, 0x000000FF);
		assignSecondBitB(secondB, HEXa_ctrl_ptr, 0x0000FF00);
		assignMinuteBitA(minuteB, HEXa_ctrl_ptr, 0x00FF0000);
		assignMinuteBitB(minuteB, HEXa_ctrl_ptr, 0xFF000000);
		assignHourBitA(hourB, HEXb_ctrl_ptr, 0x000000FF);
		assignHourBitB(hourB, HEXb_ctrl_ptr, 0x0000FF00);
	}

	// Draw the numbers onto the VGA screen
	// Reset LEDR pointer address
	*LEDR_ctrl_ptr = 0b0000000000;
	
	short int hourATenDigitColour[20][10];
	short int hourAOnesDigitColour[20][10];
	short int minuteATenDigitColour[20][10];
	short int minuteAOnesDigitColour[20][10];
	short int secondATenDigitColour[20][10];
	short int secondAOnesDigitColour[20][10];
	short int hourBTenDigitColour[20][10];
	short int hourBOnesDigitColour[20][10];
	short int minuteBTenDigitColour[20][10];
	short int minuteBOnesDigitColour[20][10];
	short int secondBTenDigitColour[20][10];
	short int secondBOnesDigitColour[20][10];

	// Set first time colours
	drawBitA(secondA, secondAOnesDigitColour);
	drawBitB(secondA, secondATenDigitColour);
	drawBitA(minuteA, minuteAOnesDigitColour);
	drawBitB(minuteA, minuteATenDigitColour);
	drawBitA(hourA, hourAOnesDigitColour);
	drawBitB(hourA, hourATenDigitColour);

	// Set the second time colours
	drawBitA(secondB, secondBOnesDigitColour);
	drawBitB(secondB, secondBTenDigitColour);
	drawBitA(minuteB, minuteBOnesDigitColour);
	drawBitB(minuteB, minuteBTenDigitColour);
	drawBitA(hourB, hourBOnesDigitColour);
	drawBitB(hourB, hourBTenDigitColour);

	// Draw the numbers at their appropriate locations on the FPGA
	for (int x=0; x<10; x++)
	{
		for (int y=0; y<20; y++)
		{
			plot_pixel(120+x, 60+y, hourATenDigitColour[y][x]);
			plot_pixel(135+x, 60+y, hourAOnesDigitColour[y][x]);
			plot_pixel(155+x, 60+y, minuteATenDigitColour[y][x]);
			plot_pixel(170+x, 60+y, minuteAOnesDigitColour[y][x]);
			plot_pixel(190+x, 60+y, secondATenDigitColour[y][x]);
			plot_pixel(205+x, 60+y, secondAOnesDigitColour[y][x]);
			
			plot_pixel(120+x, 120+y, hourBTenDigitColour[y][x]);
			plot_pixel(135+x, 120+y, hourBOnesDigitColour[y][x]);
			plot_pixel(155+x, 120+y, minuteBTenDigitColour[y][x]);
			plot_pixel(170+x, 120+y, minuteBOnesDigitColour[y][x]);
			plot_pixel(190+x, 120+y, secondBTenDigitColour[y][x]);
			plot_pixel(205+x, 120+y, secondBOnesDigitColour[y][x]);
		}
	}

	// Draw the squares between that separate the hour from the minute and second numbers
	short int box[2][2];
	boxShape(box);
	
	for (int x=0; x<2; x++)
	{
		for (int y=0; y<2; y++)
		{
			plot_pixel(149+x, 66+y, box[x][y]);
			plot_pixel(149+x, 73+y, box[x][y]);
			plot_pixel(149+x, 126+y, box[x][y]);
			plot_pixel(149+x, 132+y, box[x][y]);
			plot_pixel(184+x, 66+y, box[x][y]);
			plot_pixel(184+x, 73+y, box[x][y]);
			plot_pixel(184+x, 126+y, box[x][y]);
			plot_pixel(184+x, 132+y, box[x][y]);
		}
	}

	return 0;
}