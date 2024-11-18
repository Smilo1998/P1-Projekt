#include "../include/header.h" 

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean værdi i et struct student_profile
student_profile addStudent(void){
    student_profile user_profile;

    printf("Enter your grade average: ");
    scanf(" %lf", &user_profile.gpa);
    subjectInput(&user_profile);

    return user_profile;
}  

//Spørger efter hvert fag og svaret modtages i 1 eller 0 for at gøre det nemmere i fremtiden. kan altid ændres.
void subjectInput(student_profile *user_profile){
    int i;
    char* subjects_print[10];

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
    
    for(i = 0; i < 10; i++){
        do{
        printf("Type 1 if you completed following subjects, 0 if you have not completed the subject.\n");
        printf("%s: ", subjects_print[i]);
        scanf("%d", &user_profile->fag_array[i]);
        }while(user_profile->fag_array[i] != 0 && user_profile->fag_array[i] != 1);
    }
}


