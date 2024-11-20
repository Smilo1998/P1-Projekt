#include "../include/header.h"
#define ANTAL_ELEVER 3
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