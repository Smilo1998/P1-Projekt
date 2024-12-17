#include "../include/header.h"
#include "../include/knn.h"

// K-Nearest-Neighbours Algoritme finder den elev som brugeren er taettest paa
void kNN(student_profile user, student_profile profiles[], student_profile neighbours[]){
    int i;
    double distance = INFINITY;
    double minimum[3] = {INFINITY, INFINITY, INFINITY};

    // Omdanner user student profile til et array for at klargoere til KNN
    double *processed_user = preprocessStudentStructs(user);

    // Normaliserer værdierne i arrayet til mellem 0 og 1 og definerer en vægtfordeling
    normalizeAndWeightDistribute(processed_user, ARRAY_SIZE);
    
    // Gennemloeber alle student profiles
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        double minimum_grade = findMinimumGrade(profiles[i].education_choice.min_grade, MAX_CITY); // Finder den mindste karakter som ikke er 0 i min_grade array

        if (user.gpa >= (minimum_grade - 0.5)){  // Tjekker om brugerens karaktergennemsnit er større end den mindste adgangskvotient for uddannelsen profile[i] har studeret på
            // Den pågælende elevprofil gemmes i et double array for at klargøre til beregninger i manhattanDistance
            double *processed_data_profile = preprocessStudentStructs(profiles[i]);
            // Data i array normaliseres til værdier mellem 0 og 1. Vægttildeling defineres.
            normalizeAndWeightDistribute(processed_data_profile, ARRAY_SIZE);
            // Distancen mellem elev og bruger udregnes via manhattanDistance
            distance = manhattanDistance(processed_user, processed_data_profile);
            // Hvis distancen mellem user og profile er mindre end nuværende minimum bliver distance det nye minimum og index gemmes
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
            } else if (distance < minimum[1]){
                //sæt tredje tætteste profil
                minimum[2] = minimum[1];
                neighbours[2] = neighbours[1];
                //Ny anden tætteste profil
                minimum[1] = distance;
                neighbours[1] = profiles[i];
            } else if (distance < minimum[2]){ 
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

// Funktion som omdanner parametre fra structs til et langt array
double *preprocessStudentStructs(student_profile student){
    int i = 0;
    double *processed_student = malloc(sizeof(double) * MAX_PROCESSED_DATA); // Dynamisk allokering af array
    if(processed_student == NULL){                                          
        printf("Memory allocation error in preprocessStudentStructs");       // Error handling
        exit(EXIT_FAILURE);
    }

    // Loops som ligger data fra student profile ind i arrayet
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

// Funktion som finder mindste karakterkrav på uddannelsen koblet på den bestemte elevprofil
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

// Funktion som normaliserer alt data fra det fyldte array til værdier mellem 0 og 1. Herefter bliver data tildelt vægtning efter kategori som styrer hvor meget programmet prioterer denne datas egenskab
void normalizeAndWeightDistribute(double processed_array[], int array_size){
    // Definerer minimum og maximum værdier fo hver datatype
    double gpa_min = 2.0, gpa_max = 13.0;
    double subject_level_min = 0.0, subject_level_max = 3.0;
    double subject_rating_min = 1.0, subject_rating_max = 5.0;
    double statement_priority_min = 1.0, statement_priority_max = 5.0;
    double category_min = 0.0, category_max = 125.0;

    // Definerer vægtning. Disse kan justeres efter behov med henblik på at finde den rette balance
    double gpa_weight                = 2.5;
    double subject_level_weight      = 0.2;
    double subject_rating_weight     = 0.3;
    double statement_priority_weight = 0.6;
    double category_weight           = 1.5 + 9;

    // Normalisering og vægtning af subject level
    for (int i = 0; i < NUM_OF_SUBJECTS; i++){
        processed_array[i] = subject_level_weight * ((processed_array[i] - subject_level_min) / (subject_level_max - subject_level_min));
    }
    // Normalisering og vægtning af subject rating
    for (int i = NUM_OF_SUBJECTS; i < 2 * NUM_OF_SUBJECTS; i++){
        processed_array[i] = subject_rating_weight * ((processed_array[i] - subject_rating_min) / (subject_rating_max - subject_rating_min));
    }
    // Normalisering og vægting af statement rating
    for (int i = 2 * NUM_OF_SUBJECTS; i < 2 * NUM_OF_SUBJECTS + NUM_OF_STATEMENTS; i++){
        processed_array[i] = statement_priority_weight * ((processed_array[i] - statement_priority_min) / (statement_priority_max - statement_priority_min));
    }
    // Normalisering og vægtning af gpa
    processed_array[array_size - 2] = gpa_weight * ((processed_array[array_size - 2] - gpa_min) / (gpa_max - gpa_min)); 
    // Normalisering og vægtning af category
    processed_array[array_size - 1] = category_weight * ((processed_array[array_size - 1] - category_min) / (category_max - category_min)); 
}