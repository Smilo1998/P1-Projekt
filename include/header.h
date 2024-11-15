#ifndef HEADER_H
#define HEADER_H

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Symbolske konstanter 
#define NAME_LENGTH 30
#define SUBJECT_NAME 40
#define MAX_DATA 100

// Enumeration typer til fagene
typedef enum{
    MATEMATIK = 1,
    FYSIK = 2,
    KEMI = 3,
    BIOTEKNOLOGI = 4,
    BIOLOGI = 5,
    ASTRONOMI = 6,
    GEOLOGI = 7,
    
    INFORMATIK = 10,
    PROGRAMMERING = 11,
    TEKNOLOGI = 12,
    ROBOTTEKNOLOGI = 13,
    DESIGN = 14,

    GEOGRAFI = 20,
    SAMFUNDSFAG = 21,
    HISTORIE = 22,
    RELIGION = 23,
    FILOSOFI = 24,
    PSYKOLOGI = 25,
    
    ENGELSK = 30,
    TYSK = 31,
    FRANSK = 32,
    SPANSK = 33,
    LATIN = 34,
    
    BILLEDKUNST = 40,
    MUSIK = 41,
    DRAMA = 42,
    LITTERATUR = 43,
    
    IDRAET = 50,
    SUNDHED = 51,
    
    ERHVERVSOEKONOMI = 60,
    AFSAETNING = 61,
    MARKEDSFOERING = 62,
    INNOVATION = 63,
    VIRKSOMHEDSOEKONOMI = 64,

    MEDIEFAG = 70,
    KOMMUNIKATION = 71,
    FILMANALYSE = 72,
    
    DANSK = 80,
    RETORIK = 81
} fag;



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

// Prototyper til funktioner fra Struct.c
void getStruct();

// Prototyper til funktioner fra Input.c
void inputData();



#endif 

