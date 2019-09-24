#ifndef _DRAWING_
#define _DRAWING_

volatile int pixel_buffer_start; 

// Function draws a pixel onto the VGA at a specific location
void plot_pixel(int x, int y, short int line_color);

// Function clears the screen on the VGA by drawing on all pixels black
void clear_screen();

// Function draws number zero onto the VGA screen
void drawNumberZero(short int numberColourArray[20][10]);

// Function draws number one onto the VGA screen
void drawNumberOne(short int numberColourArray[20][10]);

// Function draws number two onto the VGA screen
void drawNumberTwo(short int numberColourArray[20][10]);

// Function draws number three onto the VGA screen
void drawNumberThree(short int numberColourArray[20][10]);

// Function draws number four onto the VGA screen
void drawNumberFour(short int numberColourArray[20][10]);

// Function draws number five onto the VGA screen
void drawNumberFive(short int numberColourArray[20][10]);

// Function draws number six onto the VGA screen
void drawNumberSix(short int numberColourArray[20][10]);

// Function draws number seven onto the VGA screen
void drawNumberSeven(short int numberColourArray[20][10]);

// Function draws number eight onto the VGA screen
void drawNumberEight(short int numberColourArray[20][10]);

// Function draws number nine onto the VGA screen
void drawNumberNine(short int numberColourArray[20][10]);

// Function draws a box onto the VGA screen
void boxShape(short int numberColourArray[2][2]);

// Function draws ones digit of the second, minute, or hour variable
void drawBitA(int number, short int colour[20][10]);

// Function draws tens digit of the second, minute, or hour variable
void drawBitB(int number, short int colour[20][10]);

#endif	// Don't include file again
