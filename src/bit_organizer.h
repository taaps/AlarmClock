#ifndef _BIT_ORGANIZER_
#define _BIT_ORGANIZER_

// Assign the appropriate bits onto the address for the ones digit of the second variable
void assignSecondBitA(int number, volatile int * address, int type);

// Assign the appropriate bits onto the address for the tens digit of the second variable
void assignSecondBitB(int number, volatile int * address, int type);

// Assign the appropriate bits onto the address for the ones digit of the minute variable
void assignMinuteBitA(int number, volatile int * address, int type);

// Assign the appropriate bits onto the address for the tens digit of the minute variable
void assignMinuteBitB(int number, volatile int * address, int type);

// Assign the appropriate bits onto the address for the ones digit of the hour variable
void assignHourBitA(int number, volatile int * address, int type);

// Assign the appropriate bits onto the address for the tens digit of the hour variable
void assignHourBitB(int number, volatile int * address, int type);

#endif