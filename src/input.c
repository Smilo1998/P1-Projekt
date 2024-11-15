#include "../include/header.h" 

// Funktion som tager input fra bruger og gemmer gpa og favorite subject i et struct student_profile
student_profile addStudent(){
        student_profile user_profile;

        printf("Enter your grade average: ");
        scanf("%lf", &user_profile.gpa);

        subjectInput();

        user_profile.fag_array;

        return user_profile;
    }  


int *subjectInput(){
    int current_subject, i;
    int subjects_print[10];
    int subjects_choice[10];
    subjects_print[0] = "Matematik";
    subjects_print[1] = "Fysik";
    subjects_print[2] = "Kemi";
    subjects_print[3] = "Biologi";
    subjects_print[4] = "Dansk";
    subjects_print[5] = "Engelsk";
    subjects_print[6] = "Historie";
    subjects_print[7] = "Samfundsfag";
    subjects_print[8] = "Virksomhedsoekonomi";
    subjects_print[9] = "Afsaetning";
    
    int i = 0;
    for(i = 0; i < 10; i++){
        printf("%s: ", subjects_print[i]);
        scanf("%s", &subjects_choice[i]);
    }

    return *subjects_choice;
}


