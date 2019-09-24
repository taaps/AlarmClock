#ifndef _DRAWING_
#define _DRAWING_

volatile int pixel_buffer_start; 

// Function draws a pixel onto the VGA at a specific location
void plot_pixel(int x, int y, short int line_color);

// Function clears the screen on the VGA by drawing on all pixels black
void clear_screen();

// Function draws number zero onto the VGA screen
void numberZero(short int numberColourArray[20][10]);

// Function draws number one onto the VGA screen
void numberOne(short int numberColourArray[20][10]);

// Function draws number two onto the VGA screen
void numberTwo(short int numberColourArray[20][10]);

// Function draws number three onto the VGA screen
void numberThree(short int numberColourArray[20][10]);

// Function draws number four onto the VGA screen
void numberFour(short int numberColourArray[20][10]);

// Function draws number five onto the VGA screen
void numberFive(short int numberColourArray[20][10]);

// Function draws number six onto the VGA screen
void numberSix(short int numberColourArray[20][10]);

// Function draws number seven onto the VGA screen
void numberSeven(short int numberColourArray[20][10]);

// Function draws number eight onto the VGA screen
void numberEight(short int numberColourArray[20][10]);

// Function draws number nine onto the VGA screen
void numberNine(short int numberColourArray[20][10]);

// Function draws a box onto the VGA screen
void boxShape(short int numberColourArray[2][2]);

#endif	// Don't include file again