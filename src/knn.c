#include "../include/header.h"
#include "../include/knn.h"

// K-Nearest-Neighbours Algoritme finder den elev som brugeren er taettest paa
void kNN(student_profile user, student_profile profiles[], student_profile neighbours[]){
    int i;
    double distance = INFINITY;
    double minimum[3] = {INFINITY, INFINITY, INFINITY};

    // Omdanner user student profile til et array for at klargoere til KNN
    double *processed_user = preprocessStudentStructs(user);

    // Gennemloeber alle student profiles
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        double minimum_grade = findMinimumGrade(profiles[i].education_choice.min_grade, MAX_CITY); // Finder den mindste karakter som ikke er 0 i min_grade array

        if (user.gpa >= (minimum_grade - 0.5)){  // Tjekker om brugerens karaktergennemsnit er større end den mindste adgangskvotient for uddannelsen profile[i] har studeret på
            // Den pågælende elevprofil gemmes i et double array for at klargøre til beregninger i mmanhattanDistance
            double *processed_data_profile = preprocessStudentStructs(profiles[i]);
            // Distancen mellem elev og bruger udregnes via manhattanDistance
            distance = manhattanDistance(processed_user, processed_data_profile);
            // Hvis distancen mellem user og profile er mindre end nuværende minimum bliver distance det nye minimum og index gemmes
            printf("DISTANCE TIL PERSON %lf: %lf\n", profiles[i].gpa, distance);
            if (distance < minimum[0]){
                //Ryk profilens placering ned i neighbours arrayet. 
                minimum[2] = minimum[1];
                neighbours[2] = neighbours[1];

                //sæt anden tætteste profil
                minimum[1] = minimum[0];
                neighbours[1] = neighbours[0];
                
                //Ny tætteste profil
                minimum[0] = distance;
                neighbours[0] = profiles[i];
            }
            else if (distance < minimum[1]){
                //sæt tredje tætteste profil
                minimum[2] = minimum[1];
                neighbours[2] = neighbours[1];

                //Ny anden tætteste profil
                minimum[1] = distance;
                neighbours[1] = profiles[i];
            }
            else if (distance < minimum[2]){
                //ny tredje tætteste profil
                minimum[2] = distance;
                neighbours[2] = profiles[i];
            }
        // Fjerner dynamisk allokering for profile
        free(processed_data_profile); 
        }
    }
    // Fjerner dynamisk allokering for user
    free(processed_user);
}

// Funktion der beregner Manhattan Distance
double manhattanDistance(const double array_user[], const double array_profile[]){ //Funktionen modtager to arrays. 1 bruger array og 1 elevprofil
    int i; 
    double result = 0;
    // Udregner summen af forskellen mellem de to arrays
    for(i = 0; i < MAX_PROCESSED_DATA; i++){
        result += fabs((array_user[i]-array_profile[i])); // Summerer den absolutte værdi af forskellen i hvert indeks mellem bruger og elevprofil array. 
    }
    return result;
}

// Funktion som omdanner structs til arrays
double *preprocessStudentStructs(student_profile student){
    int i = 0;
    double *processed_student = malloc(sizeof(double) * MAX_PROCESSED_DATA); // TILFØJ FREE SENERE I PROGRAMMET;
    if(processed_student == NULL){
        printf("Memory allocation error in preprocessStudentStructs");
        exit(EXIT_FAILURE);
    }
    
    for(i = 0; i < NUM_OF_SUBJECTS; i++){
        processed_student[i] = (double)student.fag_array[i];
    }

    for(int q = 0; q < NUM_OF_SUBJECTS; q++){
        processed_student[i] = (double)student.subject_rating[q];
        i++;
    }

    for(int k = 0; k < NUM_OF_STATEMENTS; k++){
        processed_student[i] = (double)student.statement_rating[k];
        i++;
    }

    processed_student[i] = student.gpa;
    i++;

    processed_student[i] = (double)student.category;

    return processed_student;
}

double findMinimumGrade(double min_grade[], int size){
    int i;
    double minimum = INFINITY;
    
    for(i = 0; i < size; i++){
        if(min_grade[i] < minimum && min_grade[i] != 0){
            minimum = min_grade[i];
        }
    }
    return minimum;
}