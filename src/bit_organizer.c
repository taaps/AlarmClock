#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Assign the appropriate bits onto the address for the ones digit of the second variable
void assignSecondBitA(int number, volatile int * address, int type)
{
	*address = (*address) | type;

	if ((number%10) == 0) 
		*address = (*address) & 0b11111111111111111111111100111111;
	else if ((number%10) == 1) 
		*address = (*address) & 0b11111111111111111111111100000110;
	else if ((number%10) == 2) 
		*address = (*address) & 0b11111111111111111111111101011011;
	else if ((number%10) == 3) 
		*address = (*address) & 0b11111111111111111111111101001111;
	else if ((number%10) == 4) 
		*address = (*address) & 0b11111111111111111111111101100110;
	else if ((number%10) == 5) 
		*address = (*address) & 0b11111111111111111111111101101101;
	else if ((number%10) == 6) 
		*address = (*address) & 0b11111111111111111111111101111101;
	else if ((number%10) == 7) 
		*address = (*address) & 0b11111111111111111111111100000111;
	else if ((number%10) == 8) 
		*address = (*address) & 0b11111111111111111111111101111111;
	else if ((number%10) == 9) 
		*address = (*address) & 0b11111111111111111111111101100111;
}

// Assign the appropriate bits onto the address for the tens digit of the second variable
void assignSecondBitB(int number, volatile int * address, int type)
{
	*address = (*address) | type;

	if (((secondA/10)%10) == 0) 
		*address = (*address) & 0b11111111111111110011111111111111;
	else if (((secondA/10)%10) == 1) 
		*address = (*address) & 0b11111111111111110000011011111111;
	else if (((secondA/10)%10) == 2) 
		*address = (*address) & 0b11111111111111110101101111111111;
	else if (((secondA/10)%10) == 3) 
		*address = (*address) & 0b11111111111111110100111111111111;
	else if (((secondA/10)%10) == 4) 
		*address = (*address) & 0b11111111111111110110011011111111;
	else if (((secondA/10)%10) == 5) 
		*address = (*address) & 0b11111111111111110110110111111111;
	else if (((secondA/10)%10) == 6) 
		*address = (*address) & 0b11111111111111110111110111111111;
	else if (((secondA/10)%10) == 7) 
		*address = (*address) & 0b11111111111111110000011111111111;
	else if (((secondA/10)%10) == 8) 
		*address = (*address) & 0b11111111111111110111111111111111;
	else if (((secondA/10)%10) == 9) 
		*address = (*address) & 0b11111111111111110110011111111111;
}

void assignMinuteBitA(int number, volatile int * address, int type)
{
	*address = (*address) | type;

	if ((number%10) == 0) 
		*address = (*address) & 0b11111111001111111111111111111111;
	else if ((number%10) == 1) 
		*address = (*address) & 0b11111111000001101111111111111111;
	else if ((number%10) == 2) 
		*address = (*address) & 0b11111111010110111111111111111111;
	else if ((number%10) == 3) 
		*address = (*address) & 0b11111111010011111111111111111111;
	else if ((number%10) == 4) 
		*address = (*address) & 0b11111111011001101111111111111111;
	else if ((number%10) == 5) 
		*address = (*address) & 0b11111111011011011111111111111111;
	else if ((number%10) == 6) 
		*address = (*address) & 0b11111111011111011111111111111111;
	else if ((number%10) == 7) 
		*address = (*address) & 0b11111111000001111111111111111111;
	else if ((number%10) == 8) 
		*address = (*address) & 0b11111111011111111111111111111111;
	else if ((number%10) == 9) 
		*address = (*address) & 0b11111111011001111111111111111111;
}

void assignMinuteBitB(int number, volatile int * address, int type)
{
	*address = (*address) | type;

	if (((number/10)%10) == 0) 
		*address = (*address) & 0b00111111111111111111111111111111;
	else if (((number/10)%10) == 1) 
		*address = (*address) & 0b00000110111111111111111111111111;
	else if (((number/10)%10) == 2) 
		*address = (*address) & 0b01011011111111111111111111111111;
	else if (((number/10)%10) == 3) 
		*address = (*address) & 0b01001111111111111111111111111111;
	else if (((number/10)%10) == 4) 
		*address = (*address) & 0b01100110111111111111111111111111;
	else if (((number/10)%10) == 5) 
		*address = (*address) & 0b01101101111111111111111111111111;
	else if (((number/10)%10) == 6) 
		*address = (*address) & 0b01111101111111111111111111111111;
	else if (((number/10)%10) == 7) 
		*address = (*address) & 0b00000111111111111111111111111111;
	else if (((number/10)%10) == 8) 
		*address = (*address) & 0b01111111111111111111111111111111;
	else if (((number/10)%10) == 9) 
		*address = (*address) & 0b01100111111111111111111111111111;
}

// Assign the appropriate bits onto the address for the ones digit of the hour variable
void assignHourBitA(int number, volatile int * address, int type)
{
	*address = (*address) | type;

	if ((number%10) == 0) 
		*address = (*address) & 0b11111111111111111111111100111111;
	else if ((number%10) == 1) 
		*address = (*address) & 0b11111111111111111111111100000110;
	else if ((number%10) == 2) 
		*address = (*address) & 0b11111111111111111111111101011011;
	else if ((number%10) == 3) 
		*address = (*address) & 0b11111111111111111111111101001111;
	else if ((number%10) == 4) 
		*address = (*address) & 0b11111111111111111111111101100110;
	else if ((number%10) == 5) 
		*address = (*address) & 0b11111111111111111111111101101101;
	else if ((number%10) == 6) 
		*address = (*address) & 0b11111111111111111111111101111101;
	else if ((number%10) == 7) 
		*address = (*address) & 0b11111111111111111111111100000111;
	else if ((number%10) == 8) 
		*address = (*address) & 0b11111111111111111111111101111111;
	else if ((number%10) == 9) 
		*address = (*address) & 0b11111111111111111111111101100111;
}

// Assign the appropriate bits onto the address for the tens digit of the hour variable
void assignHourBitB(int number, volatile int * address, int type)
{
	*address = (*address) | type;

	if (((number/10)%10) == 0) 
		*address = (*address) & 0b11111111111111110011111111111111;
	else if (((number/10)%10) == 1) 
		*address = (*address) & 0b11111111111111110000011011111111;
	else if (((number/10)%10) == 2) 
		*address = (*address) & 0b11111111111111110101101111111111;
}
