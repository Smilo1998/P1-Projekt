#include "../include/header.h" 

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean vaerdi i et struct student_profile
student_profile addStudent(void){
    student_profile user_profile;
    char user_subject[SUBJECT_NAME];
    int valid_subject_input = 0;
    int valid_gpa_input = 0;

    // While-loekken gentager indtil brugeren indtaster et gyldigt input. 
    // Fungerer som fejlsirking mod stavefejl eller ugyldigt input. 
    while(!valid_gpa_input){
        printf(BOLD"Enter your grade average: "SET_TEXT_DEFAULT);
        // Tjekker at input er gyldigt ved om det er et heltal og indenfor karakterskalaen.
        if ((scanf(" %lf", &user_profile.gpa) == 1) && user_profile.gpa >= 0 && user_profile.gpa <= 13){
            valid_gpa_input = 1;
        } else {
            printf(BOLD RED"Invalid GPA!\n"SET_TEXT_DEFAULT);
        }
        //printf("Indlaeste karakter: %lf\n", user_profile.gpa);
        clearBuffer(); // Rydder inputbufferen for at forhindre ugyldige inputs i at påvirke efterfølgende input.
    }
    // Prompter og gemmer de fag brugeren har haft i et array
    subjectInput(&user_profile);

    // While-loekken gentager indtil brugeren indtaster et gyldigt input. 
    // Fungerer som fejlsirking mod stavefejl eller ugyldigt input.
    while(!valid_subject_input){
        printf(BOLD"\nWhat is your favorite subject? \n"SET_TEXT_DEFAULT);
        scanf("%s", user_subject);
        // Sammenligner brugerens input med en predefineret liste af fag
        // for at validere om det er et gyldigt input.
        int subjectValidation = favoriteSubjectDecider(user_subject);
        
        if (subjectValidation != -1){
            user_profile.favorite_subject = subjectValidation;
            valid_subject_input = 1;
        } else {
            printf(BOLD RED"Invalid subject. Type the subjects name in danish.\n"SET_TEXT_DEFAULT);
        }
    }
    subjectRating(&user_profile);

    statementRating(&user_profile);

    return user_profile;
}  

// Spoerger efter hvert fag og svaret modtages i A, B, C eller 0. 
// Derefter omdannes det henholdvis til enum-vaerdierne 1, 2, 3 eller 0 og gemmes i brugerens fag_array

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

    printf(BOLD"\nType the level at which you completed the subject (A, B or C. 0 if not completed)."SET_TEXT_DEFAULT);
    
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
                // Tildeler det foerste char fra temp til faget, som kun kan vaere enten A, B, C eller 0, hvis ovenstaaende if-tjek er bestaaet.
                switch(temp[0]){
                    case 'A': 
                        user_profile->fag_array[i] = A;
                        break;
                    case 'B': 
                        user_profile->fag_array[i] = B;
                        break;
                    case 'C': 
                        user_profile->fag_array[i] = C;
                        break;
                    case '0': 
                        user_profile->fag_array[i] = 0;
                        break;
                    default:
                        printf("fejl input fag niveau");
                        exit(EXIT_FAILURE);
                }
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
    int valid_subject_input_rating_input = 0;
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

    printf(BOLD"\nRate 1-5 on how you liked your subjects.\n" SET_TEXT_DEFAULT);

    for (i = 0; i < NUM_OF_SUBJECTS; i++){
        valid_subject_input_rating_input = 0;

        while(!valid_subject_input_rating_input){
            
            if(user_profile->fag_array[i] != 0){
                printf("\n%s: ", subjects_print[i]);
                if ((scanf("%d", &temp) == 1) && temp >= 1 && temp <= 5){
                    user_profile->subject_rating[i] = temp;
                    valid_subject_input_rating_input = 1;
                } else {
                    printf(BOLD RED"Invalid Input!\n"SET_TEXT_DEFAULT);
                }
                clearBuffer();
            }
            else{
                user_profile->subject_rating[i] = 0;
                valid_subject_input_rating_input = 1;
            }
        }
    }
}

void statementRating(student_profile *user_profile){
    int i, j;
    char *statement_print[NUM_OF_STATEMENTS];
    int valid_statement_rating_input = 0;
    int temp;
    int already_rated[6] = {0, 0, 0, 0, 0, 0};

    statement_print[0] = "Jeg prioriterer en hoej loen";
    statement_print[1] = "Jeg prioriterer arbejde med mennesker";
    statement_print[2] = "Jeg prioriterer fleksible arbejdstider";
    statement_print[3] = "Jeg prioriterer gode beskaeftigelsesmuligheder";
    statement_print[4] = "Jeg prioriterer passion for mit arbejde";

    printf(BOLD"\nAssign a priority-rating between 1-5 to each of the following statements, in order of importance to you:\n"SET_TEXT_DEFAULT);
    for (j = 0; j < NUM_OF_STATEMENTS; j++){
        printf("\n  %s",statement_print[j]);
    }
    printf(BOLD "\n\nYou can only assign a rating ONCE, in order to prioritze.\n" SET_TEXT_DEFAULT);

    for (i = 0; i < NUM_OF_STATEMENTS; i++){
        valid_statement_rating_input = 0;

        while(!valid_statement_rating_input){
            
            printf("\n%s: ", statement_print[i]);

            if ((scanf("%d", &temp) == 1) && temp >= 1 && temp <= NUM_OF_STATEMENTS){
                if (already_rated[temp] == 0){
                    user_profile->statement_rating[i] = temp;
                    already_rated[temp]++;
                    valid_statement_rating_input = 1;  
                 } else {
                    printf(BOLD RED"You have already assigned that rating!\n"SET_TEXT_DEFAULT);
                 }
            } else {
                printf(BOLD RED"Invalid Input! You must assign a rating between 1-5!\n"SET_TEXT_DEFAULT);
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