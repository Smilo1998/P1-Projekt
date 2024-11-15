#include "../include/header.h" 

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean værdi i et struct student_profile
student_profile addStudent(){
        student_profile user_profile;

        printf("Enter your grade average: ");
        scanf("%lf", &user_profile.gpa);

        user_profile.fag_array = subjectInput();

        return user_profile;
    }  

//Spørger efter hvert fag og svaret modtages i 1 eller 0 for at gøre det nemmere i fremtiden. kan altid ændres.
int subjectInput(){
    int current_subject, i;
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
    
    //alloker plads til subjects choice; //FREE PLADSEN SENERE I PROGRAMMET!
    int *subjects_choice = (int*) malloc(10*sizeof(int));

    if(subjects_choice == NULL)
        printf("ALLOCATION OF MEMORY ERROR");
        exit(EXIT_FAILURE);

    int i = 0;
    for(i = 0; i < 10; i++){
        printf("Type 1 if you completed following subjects, 0 if you have not completed the subject.\n");
        printf("%s: ", subjects_print[i]);
        scanf("%d", &subjects_choice[i]);
    }

    return *subjects_choice;
}


