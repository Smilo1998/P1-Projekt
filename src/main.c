/* INDEN DU ARBEJDER SAA LAES RETNINGSLINJER PAA GITHUB */
#include "../include/header.h"

int main(void){

    // Saetter terminal-vinduets navn til titlen paa programmet med en ANSI-Sekvens
    printf("\033]0;Education Recommendation App\007");


    runProgram();
   
    return 0;
}

void runProgram(void){

    // Opretter struct array fra vores elevprofiler og opretter en user profil igennem input 
    student_profile profiles [NUM_OF_STUDENTS];
    educations education_choice[MAX_EDUCATIONS];
    student_profile neighbours[3];

    getEducations(education_choice);
    getStudents(profiles, education_choice);
    
    // Gemmer input fra bruger i user array
    student_profile user = addStudent();

    kNN(user, profiles, neighbours);

    // Finder de elevprofiler som vores bruger minder mest om
    // Outputter til brugeren
    for(int i = 0; i < AMOUNT_OF_NEIGHBOURS; i++){
    printEducation(neighbours[i], user);
    }

}

