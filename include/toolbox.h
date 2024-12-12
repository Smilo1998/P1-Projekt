#ifndef HEADER_TOOLBOX
#define HEADER_TOOLBOX

#include "header.h"


bool standardUserInputValidation(char* userInput);
bool getInputDecimal(double* decimal);
bool getInputInt(int* integer);
bool getInputString(char* string);
void clearBuffer();
void toUpperCase (char str[]);
void resetIntArray(char arrayToReset[]);
int containsSpaces(char arrayToCheck[]);
int extraInput();

#endif