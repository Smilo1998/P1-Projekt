#include "../include/header.h"

void printEducation(student_profile student, educations educationData){
    int i, city;
    printf("Recommended education based on your inputs:");
    printf("\n%s\n", *student.education_choice.name);
    printf("Cities with this education:\n");
        for(i = 0; i < MAX_CITY; i++){
            city = student.education_choice.city[i];
            printf("%d", i);
        }
        


    printf("\nUse this link to read more:\n%s\n", *student.education_choice.link);


}