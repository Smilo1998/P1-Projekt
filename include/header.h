#ifndef HEADER_H
#define HEADER_H

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "../testing/CuTest.h"
// Symbolske konstanter 
#define NAME_LENGTH 30
#define SUBJECT_NAME 40
#define MAX_DATA 250
#define NUM_OF_STUDENTS 7
#define NUM_OF_SUBJECTS 10
#define NUM_OF_STATEMENTS 5
#define NUM_OF_CATEGORIES 5
#define MAX_PROCESSED_DATA 27
#define MAX_CITY 10
#define MAX_EDUCATIONS 7
#define AMOUNT_OF_NEIGHBOURS 3

// ANSI Escape Sequences er koder der bruges til at manipulere terminaloutput.
// De er indbygget i terminalen, og det er terminalen der fortolker og implementerer dem når de printes.
// ANSI-sekvenser:
#define SET_TEXT_DEFAULT "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BOLD    "\033[1m"
#define UNBOLD  "\033[22m"
#define UNDERLINE "\033[4m"
#define UNUNDERLINE "\033[24m"

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
    BUSINESS = 0,
    SAMFUND = 20,
    INFORMATIONSTEKNOLOGI = 40,
    VIDENSKAB = 60,
    SUNDHED_OG_MENNESKER = 80,   
} category_value;

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
    char name[MAX_DATA];
    double min_grade[MAX_CITY];
    char link[MAX_DATA];   
} educations;

// Struct til elevprofiler
typedef struct student_profile{
    double gpa;
    int fag_array[NUM_OF_SUBJECTS];
    int subject_rating[NUM_OF_SUBJECTS];
    int statement_rating[NUM_OF_STATEMENTS];
    int category;
    educations education_choice;
} student_profile;





// Tilfoej dette: #include "../include/header.h" i alle filer.

//Her kan indsaettes konstante definitioner som f.eks. #DEFINE PI 3.14...

//Her indsaettes prototyper af ALLE funktioner der laves i seperate dokumenter.
// - Det er ikke noedvendigt at indsaette prototyperne i en bestemt raekkefoelge. Men organiser dem saa man kan finde rundt i dem.

// Prototyper til testing
CuSuite *test_manhattan_GetSuite();

// Prototyper til funktioner fra struct.c
void getEducations(educations education_choice[]);
void getStudents(student_profile profiles[], educations education_choice_array[]);

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

// Prototyper til funktioner fra knn.c
double manhattanDistance(const double array_user[], const double array_profile[]);
double *preprocessStudentStructs(student_profile student);
void kNN(student_profile user, student_profile profiles[], student_profile neighbours[]);
double findMinimumGrade(double min_grade[], int size);

// Prototyper til funktioner fra output.c
void printEducation(student_profile student, student_profile user);

// Prototyper til funktioner fra main.c
int main(void);
void runProgram(void);
void welcomeMessage(int *operation);
int checkInputMain(void);




#endif 

