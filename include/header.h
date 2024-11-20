#ifndef HEADER_H
#define HEADER_H

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Symbolske konstanter 
#define NAME_LENGTH 30
#define SUBJECT_NAME 40
#define MAX_DATA 100
#define NUM_OF_STUDENTS 20
#define NUMBER_OF_BOOLS 10
#define MAX_PROCESSED_DATA 12

// Enumeration typer til fagene
typedef enum{
    MATEMATIK = 0,
    FYSIK = 1,
    KEMI = 2,
    BIOLOGI = 3,
    DANSK = 4,
    ENGELSK = 5,
    HISTORIE = 6,
    SAMFUNDSFAG = 7,
    VIRKSOMHEDSOEKONOMI = 8,
    AFSAETNING = 9,      
} fag_tal_id;



// Struct til elevprofiler
typedef struct student_profile{
    double gpa;
    int fag_array[10];
    int favorite_subject;
    char education_choice[SUBJECT_NAME + 1];
} student_profile;

// Tilfoej dette: #include "../include/header.h" i alle filer.

//Her kan indsaettes konstante definitioner som f.eks. #DEFINE PI 3.14...

//Her indsaettes prototyper af ALLE funktioner der laves i seperate dokumenter.
// - Det er ikke noedvendigt at indsaette prototyperne i en bestemt raekkefoelge. Men organiser dem saa man kan finde rundt i dem.


// Prototyper til funktioner fra Struct.c
void getStudentProfiles(student_profile profiles[]);

// Prototyper til funktioner fra Input.c
void inputData(void);
void subjectInput(student_profile *user_profile);
student_profile addStudent(void);
int favoriteSubjectDecider(char* user_subject);

// Prototyper til funktioner fra knn.c
double manhattanDistance(const double array_p[], const double array_q[]);

//Main funktion
int main(void);

double *preprocessStudentStructs(student_profile student);



#endif 

