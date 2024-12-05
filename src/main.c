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
    
    //Løkke der lader programmet køre flere gange. Hvis operation variablen bliver -1 stopper programmet helt;
    do{
        welcomeMessage(&operation);
            if(operation == -1){
                printf("\nThank you for trying our program!\n\n");
                break;
            }
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
    //Første besked når programmet starter. Introduktion
    if(*operation == 0){
        printf(BOLD"---------------------------------------------\n"SET_TEXT_DEFAULT);
        printf(BOLD"Welcome to the Education Recommendation App!\n"SET_TEXT_DEFAULT);
        printf("This app will recommend a list of educations based upon your answer to a series of questions.\n"SET_TEXT_DEFAULT);
        printf(GREEN BOLD"To start the application press 'a'\n"SET_TEXT_DEFAULT);
        printf(RED BOLD"To quit the application press 'q'\n"SET_TEXT_DEFAULT);
        *operation = checkInputMain();
        return;
    }
    //Besked når programmet kører igen efter første iteration;
    printf(BOLD"---------------------------------------------\n"SET_TEXT_DEFAULT);
    printf(GREEN BOLD"To start the application again press 'a'\n"SET_TEXT_DEFAULT);
    printf(RED BOLD"To quit the application press 'q'\n"SET_TEXT_DEFAULT);
    *operation = checkInputMain();
    return;
}

//Tager imod og tjekker om gyldigt input i startsekvensen af programmet.
int checkInputMain(void){
    int valid_level_input = 0;
    char input[5];
    
     while(!valid_level_input){ 
            scanf(" %4s", input);
            // Konverterer input til store bogstaver for at undgaa problemer med casing-forskelle under validation.
            toUpperCase(input);
            // Tjekker at input enten er A eller Q ved brug af strcmp() funktionen fra string.h biblioteket.
            if (strcmp(input, "A") == 0 || strcmp(input, "Q") == 0){
                switch(input[0]){
                    case 'A': 
                        return 1;
                    case 'Q': 
                        return -1;
                    default:
                        printf("fejl input fag niveau");
                        exit(EXIT_FAILURE);
                }
                valid_level_input = 1;
            } else{
                printf(RED BOLD"Invalid Input!\n" SET_TEXT_DEFAULT);
            }  
            clearBuffer(); // Rydder inputbufferen for at forhindre ugyldige inputs i at paavirke efterfoelgende input.
    }
}

