/* INDEN DU ARBEJDER SAA LAES RETNINGSLINJER PAA GITHUB */
#include "../include/header.h"

int main(void){
    // Opretter struct array fra vores elevprofiler og opretter en user profil igennem input 
    student_profile profiles [NUM_OF_STUDENTS];
    educations education_choice[MAX_EDUCATIONS];
    getEducations(education_choice);
    
    for(int i = 0; i < 4; i++){
        printf("%s\n", education_choice[i].name);
        for(int j = 0; j < 10; j++){
            printf("%.1f ", education_choice[i].min_grade[j]);
            printf("\n");
        }
        printf("%s\n\n", education_choice[i].link);
    }

    getStudentProfiles(profiles, education_choice);
    // Gemmer input fra bruger i user array
    student_profile user = addStudent();
    // Finder de elevprofiler som vores bruger minder mest om
    student_profile nearest_neighbour = kNN(user, profiles);
    // Outputter til brugeren
    printEducation(nearest_neighbour);
    
    
    return 0;
}


