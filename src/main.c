/* INDEN DU ARBEJDER SAA LAES RETNINGSLINJER PAA GITHUB */
#include "../include/header.h"

int main(void){

    // Saetter terminal-vinduets navn til titlen paa programmet med en ANSI-Sekvens
    printf("\033]0;Education Recommendation App\007");


    runProgram();
   
    return 0;
}

void runProgram(void){
    int operation = 0;
    // Opretter struct array fra vores elevprofiler og opretter en user profil igennem input 
    student_profile profiles [NUM_OF_STUDENTS];
    educations education_choice[MAX_EDUCATIONS];
    student_profile neighbours[3];

    getEducations(education_choice);
    getStudents(profiles, education_choice);
    

    do{
        welcomeMessage(&operation);
            if(operation == -1)
                break;
        // Gemmer input fra bruger i user array
        student_profile user = addStudent();
        kNN(user, profiles, neighbours);
        // Finder de elevprofiler som vores bruger minder mest om
        // Outputter til brugeren
        for(int i = 0; i < AMOUNT_OF_NEIGHBOURS; i++){
        printEducation(neighbours[i], user);
        }
    } while(operation >=0);

}

void welcomeMessage(int *operation){
    
    if(operation == 0){
        printf("---------------------------------------------\n");
        printf("Welcome to the Education Recommendation App\n");
        printf("This app will recommend a list of educations based upon your answer to a series of questions");
        printf("To start the application press 'a'\n");
        printf("To quit the application press 'q'\n");
        scanf("%d", operation);
        operation = 1;
        return;
    }
    printf("To start the application again press 'a'\n");
    printf("To quit the application press 'q'\n");
    



}

