/* INDEN DU ARBEJDER SAA LAES RETNINGSLINJER PAA GITHUB */
#include "../include/header.h"

int main(void){
    // Opretter struct array fra vores elevprofiler og opretter en user profil igennem input 
    student_profile profiles [NUM_OF_STUDENTS];
    educations education_choice[MAX_EDUCATIONS];
    getEducationData(education_choice);
    getStudentProfiles(profiles, education_choice);
    student_profile user = addStudent();
    // Finder de elevprofiler som vores bruger minder mest om
    student_profile nearest_neighbour = kNN(user, profiles);
    // Outputter til brugeren

    printf("\n%s\n", *nearest_neighbour.education_choice.name);
    printf("\n%s\n", *nearest_neighbour.education_choice.link);
    
    
    
    return 0;
}


