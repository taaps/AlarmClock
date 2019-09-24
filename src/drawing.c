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

// Function draws number zero onto the VGA screen
void numberZero(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (i==0 || i==9 || j==0 || j==19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws number one onto the VGA screen
void numberOne(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (i >= 3 && i <=5)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws number two onto the VGA screen
void numberTwo(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (j==0)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (i==9 && (j>=0 && j <= 9))
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (j == 9)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (i==0 && (j>=9 && j <20))
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (j == 19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws number three onto the VGA screen
void numberThree(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (i==9)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (j==0 || j==9 || j==19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws number four onto the VGA screen
void numberFour(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (j==11)
			{
				numberColourArray[j][i] = 0x001F;	
			}
			else if (i>=0 && i<=1 && j>=0 && j<=11)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (i>=4 && i<=5 && j>=7 && j<=19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}	
	}
}

// Function draws number five onto the VGA screen
void numberFive(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (j==0 || j==9 || j==19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (i==0 && j>=0 && j<=9)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (i==9 && j>=9 && j<=19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else 
			{
				numberColourArray[j][i] = 0;
			}
		}
	}	
}

// Function draws number six onto the VGA screen
void numberSix(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (j==0 || j==9 || j==19 || i==0)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (i==9 && j>=9 && j<=19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws number seven onto the VGA screen
void numberSeven(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (i==9 || j==0)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws number eight onto the VGA screen
void numberEight(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (i==0 || i==9 || j==0 || j==9 || j==19)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws number nine onto the VGA screen
void numberNine(short int numberColourArray[20][10])
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<20; j++)
		{
			if (i==9 || j==0 || j==9)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else if (i==0 && j>=0 && j<=9)
			{
				numberColourArray[j][i] = 0x001F;
			}
			else
			{
				numberColourArray[j][i] = 0;
			}
		}
	}
}

// Function draws a box onto the VGA screen
void boxShape(short int numberColourArray[2][2])
{
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			numberColourArray[i][j] = numberColourArray[j][i] = 0x001F;
		}
	}
}

// Function draws ones digit of the second, minute, or hour variable
void drawBitA(int number, short int colour[20][10])
{
	if ((number%10)==0)	
		numberZero(colour);
	else if ((number)==1)	
		numberOne(colour);
	else if ((number%10)==2)	
		numberTwo(colour);
	else if ((number)==3)	
		numberThree(colour);
	else if ((number%10)==4)	
		numberFour(colour);
	else if ((number%10)==5)	
		numberFive(colour);
	else if ((number%10)==6)	
		numberSix(colour);
	else if ((number%10)==7)	
		numberSeven(colour);
	else if ((number%10)==8)	
		numberEight(colour);
	else if ((number%10)==9)	
		numberNine(colour);
}

// Function draws tens digit of the second, minute, or hour variable
void drawBitB(int number, short int colour[20][10])
{
	if (((number/10)%10)==0)	
		numberZero(colour);
	else if (((number/10)%10)==1)	
		numberOne(colour);
	else if (((number/10)%10)==2)	
		numberTwo(colour);
	else if (((number/10)%10)==3)	
		numberThree(colour);
	else if (((number/10)%10)==4)	
		numberFour(colour);
	else if (((number/10)%10)==5)	
		numberFive(colour);
	else if (((number/10)%10)==6)	
		numberSix(colour);
	else if (((number/10)%10)==7)	
		numberSeven(colour);
	else if (((number/10)%10)==8)	
		numberEight(colour);
	else if (((number/10)%10)==9)	
		numberNine(colour);
}
