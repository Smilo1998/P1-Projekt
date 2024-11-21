#ifndef HEADER_H
#define HEADER_H

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Symbolske konstanter 
#define NAME_LENGTH 30
#define SUBJECT_NAME 40
#define MAX_DATA 250
#define NUM_OF_STUDENTS 3
#define NUMBER_OF_BOOLS 10
#define MAX_PROCESSED_DATA 12
#define MAX_CITY 10
#define MAX_EDUCATIONS 20

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

typedef enum{
    A = 3,
    B = 2,
    C = 1,
} fag_niveau;

typedef enum{
    KOEBENHAVN = 0,
    AARHUS = 1,
    ODENSE = 2,
    AALBORG = 3,
    ESBJERG = 4,
    RANDERS = 5, 
    HORSENS = 6,
    KOLDING = 7,
    VEJLE = 8,
    ROSKILDE = 9,
} cities;

// Struct til videregående uddannelser
typedef struct educations{
    char *name[MAX_DATA];
    double min_grade[MAX_CITY];
    int city[MAX_CITY];
    char *link[MAX_DATA];   
} educations;

// Struct til elevprofiler
typedef struct student_profile{
    double gpa;
    int fag_array[10];
    int favorite_subject;
    educations education_choice;
} student_profile;





// Tilfoej dette: #include "../include/header.h" i alle filer.

//Her kan indsaettes konstante definitioner som f.eks. #DEFINE PI 3.14...

//Her indsaettes prototyper af ALLE funktioner der laves i seperate dokumenter.
// - Det er ikke noedvendigt at indsaette prototyperne i en bestemt raekkefoelge. Men organiser dem saa man kan finde rundt i dem.


// Prototyper til funktioner fra Struct.c
void getStudentProfiles(student_profile profiles[],  educations education_choice_array[]);
void getEducationData(educations education_choice[]);

// Prototyper til funktioner fra Input.c
void inputData(void);
void subjectInput(student_profile *user_profile);
student_profile addStudent(void);
int favoriteSubjectDecider(char* user_subject);
void toUpperCase (char str[]);

// Prototyper til funktioner fra knn.c
double manhattanDistance(const double array_user[], const double array_profile[]);
double *preprocessStudentStructs(student_profile student);
student_profile kNN(student_profile user, student_profile profiles[]);

//Main funktion
int main(void);





#endif 

