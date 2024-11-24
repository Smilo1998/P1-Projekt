#include "../include/header.h"

// K-Nearest-Neighbours Algoritme finder den elev som brugeren er taettest paa
student_profile kNN(student_profile user, student_profile profiles[]){
    int i;
    int index = -1;
    double distance = 1000000;
    double minimum = 999999;

    // Omdanner user student profile til et array for at klargoere til KNN
    double *processed_user = preprocessStudentStructs(user);

    for(i = 0; i < NUM_OF_STUDENTS; i++){
        double minimum_grade = findMinimumGrade(profiles[i].education_choice.min_grade, MAX_CITY); // Finder den mindste karakter som ikke er 0 i min_grade array

        if (user.gpa >= minimum_grade){ 
            // Profiles structen gemmes i et double array
            double *processed_data_profile = preprocessStudentStructs(profiles[i]);
            distance = manhattanDistance(processed_user, processed_data_profile);
            // Hvis distancen mellem user og profile er mindre end nuværende minimum bliver distance det nye minimum og index gemmes
            if (distance <= minimum){
                minimum = distance;
                index = i;
            }
        // Fjerner dynamisk allokering for profile
        free(processed_data_profile); 
        }
    }
    // Fjerner dynamisk allokering for user
    free(processed_user);
    // Hvis ingen bruger findes fastholdes index på -1 og programmet finder altså ikke en uddannelse der matcher personen
    if (index == -1) {
        printf("No suitable profile found.\n");
        exit(EXIT_FAILURE);
    }
    // Returner den profil som passer bedst med user
    return profiles[index];
}

// Funktion der beregner Manhattan Distance
double manhattanDistance(const double array_user[], const double array_profile[]){
    int i; 
    double result = 0;
    // Udregner summen af forskellen mellem de to arrays
    for(i = 0; i < MAX_PROCESSED_DATA; i++){
        result += fabs((array_user[i]-array_profile[i])); // Summerer 
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

double findMinimumGrade(double min_grade[], int size){
    int i;
    double minimum = min_grade[0];

    for(i = 0; i < size; i++){
        if(min_grade[i] < minimum && min_grade[i] != 0){
            minimum = min_grade[i];
        }
    }
    return minimum;
}