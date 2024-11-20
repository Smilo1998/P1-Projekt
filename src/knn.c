#include "../include/header.h"

// K-Nearest-Neighbours Algoritme finder den elev som brugeren er taettest paa
student_profile kNN(student_profile user, student_profile profiles[]){
    int i;
    int index;
    double distance;
    double minimum = 5000;

    // Omdanner user student profile til et array for at klargoere til KNN
    double processed_user[MAX_PROCESSED_DATA];
    *processed_user = *preprocessStudentStructs(user);

    for(i = 0; i < NUM_OF_STUDENTS; i++){
        double processed_data_profile[MAX_PROCESSED_DATA];
        *processed_data_profile = *preprocessStudentStructs(profiles[i]);
        distance = manhattanDistance(processed_user, processed_data_profile);
        if (distance <= minimum){
            minimum = distance;
            index = i;
        }
    }
    printf("index: %d\n", index);
    printf("i = %d\n", i);
    return profiles[index];
}

// Funktion der beregner Manhattan Distance
double manhattanDistance(const double array_user[], const double array_profile[]){
    int i; 
    double result = 0;
    for(i = 0; i < MAX_PROCESSED_DATA; i++){
        result += fabs(array_user[i]-array_profile[i]); // Summerer 
    }
    return result;
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