#ifndef HEADER_KNN
#define HEADER_KNN

#include "header.h"

// Prototyper til funktioner fra knn.c
double manhattanDistance(const double array_user[], const double array_profile[]);
double *preprocessStudentStructs(student_profile student);
void kNN(student_profile user, student_profile profiles[], student_profile neighbours[]);
void normalizeAndWeightDistribute(double processed_array[], int array_size);
double findMinimumGrade(double min_grade[], int size);

#endif
