#include "../include/header.h"

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

/*
// Struct eksempel.
struct Point{
    int x, y;
    bool label;
}

//Beregner Euclidean distance imellem to punkter.
double euclidean_distance(const int Point p1, const Point& p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Funktion til at finde K nærmeste naboer
bool knn_class(){

}
*/


// Sorter elever 
