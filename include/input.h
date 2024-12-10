#ifndef HEADER_INPUT
#define HEADER_INPUT

#include "header.h"

// Prototyper til funktioner fra input.c
void inputData(void);
void subjectInput(student_profile *user_profile);
student_profile addStudent(void);
void subjectRating(student_profile *user_profile);
void statementRating(student_profile *user_profile);
void clearBuffer();
void toUpperCase (char str[]);
int categoryDecider(char* user_category);
void categoryRating(student_profile *user_profile);

#endif
