#include "../include/header.h"

void printEducation(student_profile student, student_profile user){
    int i;
    printf("---------------------------------------------");
    printf(BOLD"\nRecommended education based on your inputs:\n"UNBOLD);
    printf("\n%s\n\n", student.education_choice.name);
    printf(BOLD"Cities with this education:\n"UNBOLD);

        for(i = 0; i < MAX_CITY; i++){
            delay(50);
            if (student.education_choice.min_grade[i] >= 2){
                switch(i){
                    case 0:
                        printf(BOLD"\nKoebenhavn\n");
                        break;
                    case 1:
                        printf(BOLD"\nAarhus\n");
                        break;
                    case 2:
                        printf(BOLD"\nOdense\n");
                        break;
                    case 3:
                        printf(BOLD"\nAalborg\n");
                        break;
                    case 4:
                        printf(BOLD"\nEsbjerg\n");
                        break;
                    case 5:
                        printf(BOLD"\nRanders\n");
                        break;
                    case 6:
                        printf(BOLD"\nHorsens\n");
                        break;
                    case 7:
                        printf(BOLD"\nKolding\n");
                        break;
                    case 8:
                        printf(BOLD"\nVejle\n");
                        break;
                    case 9:
                        printf(BOLD"\nRoskilde\n");
                        break;
                    default:
                        printf("Fejl i switch output");
                        break;
                }
                printf(UNBOLD"Previous year kvote 1 grade requirement: ");
                    if (user.gpa >= student.education_choice.min_grade[i]){
                        printf(GREEN);
                    } else if (user.gpa >= student.education_choice.min_grade[i] - 0.5) {
                        printf(YELLOW);
                    } else {
                        printf(RED);
                    }
                printf(BOLD"%.1f\n"SET_TEXT_DEFAULT, student.education_choice.min_grade[i]);
            }
        }
    printf("\nUse this link to read more:\n%s\n\n", student.education_choice.link);
}

void delay(int milliseconds) {
#ifdef _WIN32 // Tjekker om systemet er Windows. Da Windows og Linux/Mac skal bruge to forskellige 'sleep' funktioner.
    Sleep(milliseconds);  // Windows
#else
    usleep(milliseconds * 1000);  // Linux/macOS. Ganges med 1000 fordi 'usleep' tager mikrosekunder vs 'Sleep' der tager millisekunder,
#endif
}