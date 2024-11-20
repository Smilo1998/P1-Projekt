#include "../include/header.h" 

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean værdi i et struct student_profile
student_profile addStudent(void){
    student_profile user_profile;
    char user_subject[SUBJECT_NAME];
    int valid_subject = 0;

    // Prompter efter brugers karaktergennemsnit
    printf("Enter your grade average: ");
    scanf(" %lf", &user_profile.gpa);
    // Prompter og gemmer de fag brugeren har haft i et boolean array
    subjectInput(&user_profile);
    // Prompter efter brugerens yndlingsfag
    
    while(!valid_subject){

        printf("What is your favorite subject? \n");
        scanf("%s", user_subject);

        int subjectValidation = favoriteSubjectDecider(user_subject);
        if (subjectValidation != -1)
        {
            user_profile.favorite_subject = subjectValidation;
            valid_subject = 1;
        }
        else
        {
            printf("Invalid subject. Type the subjects name in danish.\n");
        }
    
    }
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


//Tager et string array som input og gennemgår hvert index og konverterer det til et Uppercase bogstav
void toUpperCase (char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}

int favoriteSubjectDecider(char* user_subject){
    // *user_subject = strlwr(user_subject);  
    // printf("User subject: %s \n", user_subject);  

    // Konverterer til store bogstaver før sammenligning
    toUpperCase(user_subject); 

    if (strcmp(user_subject, "MATEMATIK") == 0) {
        return MATEMATIK;
    } else if (strcmp(user_subject, "FYSIK") == 0) {
        return FYSIK;
    } else if (strcmp(user_subject, "KEMI") == 0) {
        return KEMI;
    } else if (strcmp(user_subject, "BIOLOGI") == 0) {
        return BIOLOGI;
    } else if (strcmp(user_subject, "DANSK") == 0) {
        return DANSK;
    } else if (strcmp(user_subject, "ENGELSK") == 0) {
        return ENGELSK;
    } else if (strcmp(user_subject, "HISTORIE") == 0) {
        return HISTORIE;
    } else if (strcmp(user_subject, "SAMFUNDSFAG") == 0) {
        return SAMFUNDSFAG;
    } else if (strcmp(user_subject, "VIRKSOMHEDSOEKONOMI") == 0) {
        return VIRKSOMHEDSOEKONOMI;
    } else if (strcmp(user_subject, "AFSAETNING") == 0) {
        return AFSAETNING;
    } else {
        return -1; // Ukendt fag
    }
}





