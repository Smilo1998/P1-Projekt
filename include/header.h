#ifndef HEADER_H
#define HEADER_H

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Symbolske konstanter 
#define NAME_LENGTH 30
#define SUBJECT_NAME 40
#define MAX_DATA 100



// Struct til elevprofiler
typedef struct student_profile{
    double gpa;
    char favorite_subject[SUBJECT_NAME + 1];
    char education_choice[SUBJECT_NAME + 1]
} student_profile;

// Tilfoej dette: #include "../include/header.h" i alle filer.

//Her kan indsaettes konstante definitioner som f.eks. #DEFINE PI 3.14...

//Her indsaettes prototyper af ALLE funktioner der laves i seperate dokumenter.
// - Det er ikke noedvendigt at indsaette prototyperne i en bestemt raekkefoelge. Men organiser dem saa man kan finde rundt i dem.

// Funktioner fra Struct.c
void getStruct();



#endif 

