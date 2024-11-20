/* INDEN DU ARBEJDER SAA LAES RETNINGSLINJER PAA GITHUB */
#include "../include/header.h"

int main(void){
    student_profile profiles [NUM_OF_STUDENTS];

    student_profile user = addStudent();
    
    printf("User GPA: %.2f\n", user.gpa);
    for (int i = 0; i < 10; i++){
        printf("%d ", user.fag_array[i]);
    }
    printf("\n");

    printf("User favorite subject: %d in integer type\n", user.favorite_subject);
    
    return 0;
}


