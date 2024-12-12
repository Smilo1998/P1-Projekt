/* P1 Gr 8*/
#include "../include/header.h"
#include "../include/toolbox.h"
#include "../include/input.h"
#include "../include/output.h"
#include "../include/knn.h"
#include "../include/struct.h"

//Main funktion der starter programmet
int main(void){
    

    runProgram();
   
    return 0;
}

//Funktion der kører den overordnede udførelses sekvens
void runProgram(void){
    // Saetter terminal-vinduets navn til titlen paa programmet med en ANSI-Sekvens
    printf("\033]0;Education Recommendation App\007");

    int operation = 0;
    // Erklærer student_profiles, education_choice og neighbours arrays til videre brug i programmet. Disse er af datatypen struct arrays.
    student_profile profiles [NUM_OF_STUDENTS];
    educations education_choice[MAX_EDUCATIONS];
    student_profile neighbours[AMOUNT_OF_NEIGHBOURS];

    //Kalder funktionerne i struct.c for at scanne data ind i arrays.
    //Get educations kaldes først da education_choice arrayet bruges i getStudents.
    getEducations(education_choice);
    getStudents(profiles, education_choice);

    //Loop der lader programmet køre flere gange. Hvis operation variablen bliver -1 stopper programmet helt;
    do{
        welcomeMessage(&operation);
            if(operation == -1){
                printf("\nThank you for trying our program!\n\n");
                break;
            }
        // Gemmer input fra bruger i user array
        student_profile user = addStudent();
        // Finder de elevprofiler som vores bruger minder mest om
        kNN(user, profiles, neighbours);
        // Outputter til brugeren
        for(int i = 0; i < AMOUNT_OF_NEIGHBOURS; i++){
        printEducation(neighbours[i], user);
        }
    } while(operation >=0);
}

//Funktion der printer prompts til overordnet kørsel af programmet
//Funktionen tager også imod brugerinput for kørslen
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
    char input[MAX_USER_INPUT_LENGTH + 1];
    
     while(1){ 
            //Bruger getInputString fra toolbox.c til at validere inputtet
            if(getInputString(input) == true){
            // Tjekker at input enten er A eller Q ved brug af strcmp() funktionen fra string.h biblioteket.
                if (strcmp(input, "A") == 0)
                    return 1;
                else if(strcmp(input, "Q") == 0)
                    return -1;
                else
                    printf(RED BOLD"Invalid Input!\n" SET_TEXT_DEFAULT);
            }
            clearBuffer(); // Rydder inputbufferen for at forhindre ugyldige inputs i at paavirke efterfoelgende input.
    }
    return 0;
}

