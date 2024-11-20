/* INDEN DU ARBEJDER SAA LAES RETNINGSLINJER PAA GITHUB */
#include "../include/header.h"

int main(void){
    student_profile profiles [NUM_OF_STUDENTS];
    getStudentProfiles(profiles);
    student_profile user = addStudent();
    
    kNN(user, profiles);

    preprocessStudentStructs(user);
    
    return 0;
}


