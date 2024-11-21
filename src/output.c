#include "../include/header.h"

void printEducation(student_profile student){
    int i;
    printf("---------------------------------------------");
    printf("\nRecommended education based on your inputs:\n");
    printf("\n%s\n\n", *student.education_choice.name);
    printf("Cities with this education:\n");
        for(i = 0; i < MAX_CITY; i++){
            if (student.education_choice.city[i] == 1){
                switch(i){
                    case 0:
                        printf("\nKoebenhavn\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 1:
                        printf("\nAarhus\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 2:
                        printf("\nOdense\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 3:
                        printf("\nAalborg\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 4:
                        printf("\nEsbjerg\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 5:
                        printf("\nRanders\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 6:
                        printf("\nHorsens\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 7:
                        printf("\nKolding\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 8:
                        printf("\nVejle\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    case 9:
                        printf("\nRoskilde\n");
                        printf("Previous year kvote 1 grade requirement: %.1f\n", student.education_choice.min_grade[i]);
                        break;
                    default:
                        printf("Fejl i switch output");
                        break;
                }
            }
        }
    printf("\nUse this link to read more:\n%s\n", *student.education_choice.link);
}
