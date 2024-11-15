#include "../include/header.h"

// Struct eksempel.
struct Point{
    int x, y;
    bool label;
}

//Beregner Euclidean distance imellem to punkter.
double euclidean_distance(const Point& p1, const Point& p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Funktion til at finde K nærmeste naboer
bool knn_class(){

}



// Sorter elever 
