#include "../include/header.h" 

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean vaerdi i et struct student_profile
student_profile addStudent(void){
    student_profile user_profile;
    char user_subject[SUBJECT_NAME];
    int valid_subject = 0;
    int valid_gpa = 0;

    // While-loekken gentager indtil brugeren indtaster et gyldigt input. 
    // Fungerer som fejlsirking mod stavefejl eller ugyldigt input. 
    while(!valid_gpa){
        printf(BOLD"Enter your grade average: "SET_TEXT_DEFAULT);
        // Tjekker at input er gyldigt ved om det er et heltal og indenfor karakterskalaen.
        if ((scanf(" %lf", &user_profile.gpa) == 1) && user_profile.gpa >= 0 && user_profile.gpa <= 13){
            valid_gpa = 1;
        } else {
            printf(BOLD RED"Invalid GPA!\n"SET_TEXT_DEFAULT);
        }
        // printf("Indlaeste karakter: %lf\n", user_profile.gpa);
        clearBuffer(); // Rydder inputbufferen for at forhindre ugyldige inputs i at påvirke efterfølgende input.
    }
    // Prompter og gemmer de fag brugeren har haft i et boolean array
    subjectInput(&user_profile);

    // While-loekken gentager indtil brugeren indtaster et gyldigt input. 
    // Fungerer som fejlsirking mod stavefejl eller ugyldigt input.
    while(!valid_subject){
        printf(BOLD"\nWhat is your favorite subject? \n"SET_TEXT_DEFAULT);
        scanf("%s", user_subject);
        // Sammenligner brugerens input med en predefineret liste af fag
        // for at validere om det er et gyldigt input.
        int subjectValidation = favoriteSubjectDecider(user_subject);
        
        if (subjectValidation != -1){
            user_profile.favorite_subject = subjectValidation;
            valid_subject = 1;
        } else {
            printf(BOLD RED"Invalid subject. Type the subjects name in danish.\n"SET_TEXT_DEFAULT);
        }
    }
    subjectRating(&user_profile);
}  

//Spoerger efter hvert fag og svaret modtages i 1 eller 0 for at goere det nemmere i fremtiden. kan altid aendres.
void subjectInput(student_profile *user_profile){
    int i;
    char* subjects_print[10];
    int valid_level_input = 0;
    char temp[5];

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

    printf(BOLD"Type the level of which you completed the subject (A, B or C. 0 if not completed)."SET_TEXT_DEFAULT);
    
    for(i = 0; i < 10; i++){
        valid_level_input = 0; // Nulstilles for at gentage loekken ved hver iteration.

        // While-loekken gentager, indtil brugeren indtaster et gyldigt input.
        // Fungerer som fejlsirking mod stavefejl eller ugyldigt input. 
        while(!valid_level_input){ 
            printf("\n%s: ", subjects_print[i]);
            scanf(" %4s", temp);
            // Konverterer input til store bogstaver for at undgaa problemer med casing-forskelle under validation.
            toUpperCase(temp);
            // Tjekker at input enten er A, B, C eller 0 ved brug af strcmp() funktionen fra string.h biblioteket.
            if (strcmp(temp, "A") == 0 || strcmp(temp, "B") == 0 || strcmp(temp, "C") == 0 || strcmp(temp, "0") == 0){
                // Tildeler det første char fra temp til faget, som kun kan vaere enten A, B, C eller 0, hvis ovenstaaende if-tjek er bestaaet.
                user_profile->fag_array[i] = temp[0];
                valid_level_input = 1;
            } else{
                printf(BOLD RED "Invalid Input!\n" SET_TEXT_DEFAULT);
            }  
            clearBuffer(); // Rydder inputbufferen for at forhindre ugyldige inputs i at paavirke efterfoelgende input.
        } 
    }
}

void subjectRating(student_profile *user_profile){
    int i;
    char *subjects_print[10];
    int valid_level_input = 0;
    int temp;

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

    printf(BOLD"\nRate 1-5 on how you liked your subjects. 0 if you dont have the subjects\n" SET_TEXT_DEFAULT);

    for (i = 0; i < 10; i++){
        valid_level_input = 0;

        while(!valid_level_input){
            printf("\n%s: ", subjects_print[i]);
            scanf("%d", &temp);

            if (temp >= 0 && temp <= 5){
                user_profile->subject_rating[i] = temp;
                valid_level_input = 1;
            } else {
                printf(BOLD RED"Invalid Input!\n"SET_TEXT_DEFAULT);
            }
            clearBuffer();
        }
    }
}

int favoriteSubjectDecider(char* user_subject){ 
    // Konverterer user_subject til store bogstaver foer sammenligning, for at fejlsikre mod casing-forskelle.
    // Goeres ved brug af toupper() funktionen fra ctype.h biblioteket.
    toUpperCase(user_subject); 

    // Sammenligner den upperCase konverteret version af user_subject med en raekke fag.
    // Ved et match returneres den tilsvarende enum vaerdi for det paagaeldende fag. Ellers returneres -1
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


// Rydder inputbufferen ved at laese og kassere alle tegn indtil ('\n') som markerer at inputbufferen er tom.
// Dette sikrer, at eventuelle resterende tegn fra forkerte inputs ikke paavirker det efterfoelgende input.
void clearBuffer(){
    while(getchar() != '\n'); 
}

// Tager et char array som input og konverterer hvert index til et Uppercase.
// Det goeres ved brug af toupper() funktionen fra ctype.h biblioteket, som omdanner smaa bogstaver til store bogstaver.
// toupper() tager kun et enkelt char som input, derfor er et for-loop noedvendigt for at konvertere hele char strings.
void toUpperCase (char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
}