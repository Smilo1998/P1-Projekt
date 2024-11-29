/* INDEN DU ARBEJDER SAA LAES RETNINGSLINJER PAA GITHUB */
#include "../include/header.h"

int main(void){
    // Opretter struct array fra vores elevprofiler og opretter en user profil igennem input 
    student_profile profiles [NUM_OF_STUDENTS];
    educations education_choice[MAX_EDUCATIONS];
    getEducations(education_choice);
    getStudents(profiles, education_choice);
    
    for(int i = 0; i < NUM_OF_STUDENTS; i++){
        printf("%lf\n", profiles[i].gpa);
        for(int j = 0; j < 10; j++){
            printf("%d ", profiles[i].fag_array[j]);
            printf("\n");
        }
        printf("%d\n\n", profiles[i].favorite_subject);
        printf("%s\n\n", profiles[i].education_choice.name);
    }

    
    // Gemmer input fra bruger i user array
    student_profile user = addStudent();
    // Finder de elevprofiler som vores bruger minder mest om
    student_profile nearest_neighbour = kNN(user, profiles);
    // Outputter til brugeren
    printEducation(nearest_neighbour);
    
    
    return 0;
}


