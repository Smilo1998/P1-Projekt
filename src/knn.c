#include "../include/header.h"

// Funktion der beregner Manhattan Distance
double manhattanDistance(const double array_p[], const double array_q[]){
    int i; 
    int lgt;
    double result = 0;
    for(int i = 0; i < lgt; i++){
        result += fabs(array1[i]-array2[i]); // Summerer 
    }
    return result;
}

// K-Nearest-Neighbours Algoritme finder den elev som brugeren er taettest paa
void kNN(const double array_p[], const double array_q[]){
    int i;
    int index;
    double minimum = 5000;

    for(i = 0; i < ANTAL_ELEVER; i++){
        distance = manhattanDistance(array_p, array_q);
        if (distance <= minimum){
            minimum = distance;
            index = i;

        }
    }
}

// Funktion som omdanner structs til arrays
double *preprocessStudentStructs(student_profile student){
    int i;
    double *processed_student = malloc(sizeof(double) * MAX_PROCESSED_DATA); // TILFØJ FREE SENERE I PROGRAMMET;
    if(processed_student == NULL){
        printf("Memory allocation error in preprocessStudentStructs");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < NUMBER_OF_BOOLS; i++){
        processed_student[i] = (double)student.fag_array[i];
    }
    processed_student[i++] = student.gpa;
    processed_student[i++] = student.favorite_subject;

    return processed_student;
}