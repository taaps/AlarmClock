#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "drawing.h"


// Function draws a pixel onto the VGA at a specific location
void plot_pixel(int x, int y, short int line_color)
{
    *(short int *)(pixel_buffer_start + (y << 10) + (x << 1)) = line_color;
}

// Function clears the screen on the VGA by drawing on all pixels black
void clear_screen()
{
	short int line_colour = 0;
	
	for (int i=0; i<320; i++)
	{
		for (int j=0; j<240; j++)
		{
			plot_pixel(i, j, line_colour);
		}
	}
}