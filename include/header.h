#ifndef HEADER_H
#define HEADER_H

#define NAME_LENGTH 30
#define SUBJECT_NAME
typedef struct elevprofil{
    char name[NAME_LENGTH + 1];
    double gpa;
    char school_type;
    char yndlingsfag[SUBJECT_NAME + 1];
} elevprofil;

// Tilfoej dette: #include "header.h" i alle filer.

//Her kan indsaettes konstante definitioner som f.eks. #DEFINE PI 3.14...

//Her indsaettes prototyper af ALLE funktioner der laves i seperate dokumenter.
// - Det er ikke noedvendigt at indsaette prototyperne i en bestemt raekkefoelge. Men organiser dem saa man kan finde rundt i dem.

// Funktioner fra Struct.c
void getStruct();



#endif 

