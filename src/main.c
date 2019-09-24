#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "drawing.h"


int main(void)
{
	volatile int * HEXa_ctrl_ptr = (int *)0xFF200020;	//pointer to HEX0-HEX3 address
	volatile int * HEXb_ctrl_ptr = (int *)0xFF200030;	//pointer to HEX4-HEX5 address
	volatile int * KEY_ctrl_ptr = (int *)0xFF200050;	//pointer to KEY0 address
	volatile int * SW_ctrl_ptr = (int *)0xFF200040;		//pointer to SW address
	volatile int * EDGECAPTURE_ctrl_ptr = (int *)0xFF20005C; //pointer to edge capture bit
	volatile int * LEDR_ctrl_ptr = (int *)0xFF200000;	//pointer to LEDR address

	int secondA = 0, minuteA = 0, hourA = 0, secondB = 0, minuteB = 0, hourB = 0;
	
	volatile int * pixel_ctrl_ptr = (int *)0xFF203020;
	pixel_buffer_start = *pixel_ctrl_ptr;
	clear_screen();
	
	*LEDR_ctrl_ptr = 0b1111111111;
	
	//first time input
	*HEXa_ctrl_ptr = 0x00000000;
	*HEXb_ctrl_ptr = 0x00000000;

	return 0;
}