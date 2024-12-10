#include "../include/header.h" 
#include "../include/input.h"

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean vaerdi i et struct student_profile
student_profile addStudent(void){
    student_profile user_profile;
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
  
    subjectRating(&user_profile);

    statementRating(&user_profile);

    categoryRating(&user_profile);

    printf("TEST");

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
                printf(RED BOLD"Invalid Input!\n" SET_TEXT_DEFAULT);
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
                    printf(RED BOLD"Invalid Input!\n"SET_TEXT_DEFAULT);
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
    int i, j, k, q, z;
    char *statement_print[NUM_OF_STATEMENTS];
    char statement_id[NUM_OF_STATEMENTS];
    int valid_statement_rating_input = 0;
    char temp[10];
    int already_rated[NUM_OF_STATEMENTS] = {0, 0, 0, 0, 0};
    int valid_redo_input = 0;
    char redoTemp[10];
    int confirmStatements = 0;

    statement_print[0] = "A) Jeg prioriterer en hoej loen";
        statement_id[0] = 'A';

    statement_print[1] = "B) Jeg prioriterer arbejde med mennesker";
        statement_id[1] = 'B';

    statement_print[2] = "C) Jeg prioriterer fleksible arbejdstider";
        statement_id[2] = 'C';

    statement_print[3] = "D) Jeg prioriterer gode beskaeftigelsesmuligheder";
        statement_id[3] = 'D';

    statement_print[4] = "E) Jeg prioriterer passion for mit arbejde";
        statement_id[4] = 'E';

    while(!confirmStatements){
        valid_redo_input = 0;

        printf(BOLD"\nAssign the following statements a priority using A, B, C, D or E, in order of importance to you:\n"SET_TEXT_DEFAULT);
        for (i = 0; i < NUM_OF_STATEMENTS; i++){
            printf("\n  %s",statement_print[i]);
        }
        printf(BOLD "\n\nYou can only assign a rating ONCE, in order to prioritze.\n" SET_TEXT_DEFAULT);

        for (j = 0; j < NUM_OF_STATEMENTS; j++){

            valid_statement_rating_input = 0;

            while(!valid_statement_rating_input){
                printf("\n%d prioritet: ", j + 1);
                
                scanf(" %9s", temp);
                toUpperCase(temp);

                if (strlen(temp) == 1 && strchr("ABCDE", temp[0]) != NULL) {

                    for (k = 0; k < NUM_OF_STATEMENTS; k++){
                        if (temp[0] == statement_id[k]){
                            if (already_rated[k] == 0){

                                user_profile->statement_rating[j] = k + 1;
                                already_rated[k]++;
                                valid_statement_rating_input = 1;
                                break;  

                            } else {
                                printf(BOLD RED"You have already assigned that rating!\n"SET_TEXT_DEFAULT);
                            }
                        }
                    }
                } else {
                printf(BOLD RED"Invalid Input! You must assign a priority with A, B, C, D or E!\n"SET_TEXT_DEFAULT);
                }
                clearBuffer();
            }
        }
        printf(BOLD"\nYour have rated the statements in the following order:\n\n"SET_TEXT_DEFAULT);
        for(q = 0; q < NUM_OF_STATEMENTS; q++){
            printf(BOLD"%d prioritet: "SET_TEXT_DEFAULT, q + 1);
            printf("%s\n",statement_print[user_profile->statement_rating[q] - 1]);
        }
        while(!valid_redo_input){
            printf(BOLD"\nType Y to confirm or R to redo the rating\n"SET_TEXT_DEFAULT);
                scanf(" %9s", redoTemp);
                toUpperCase(redoTemp);

            if (strlen(redoTemp) == 1 && strchr("YR", redoTemp[0]) != NULL){
                if (redoTemp[0] == 'Y'){
                    confirmStatements = 1;
                    valid_redo_input = 1;
                    break;
                } else if (redoTemp[0] == 'R'){
                    for (z = 0; z < NUM_OF_STATEMENTS; z++) {
                        user_profile->statement_rating[z] = 0;
                        already_rated[z] = 0;
                    }
                    valid_redo_input = 1;
                    break;
                }
            }
            else {
                printf(BOLD RED"Invalid input!"SET_TEXT_DEFAULT);
            }
            clearBuffer();
        }    
    }
}

void categoryRating(student_profile *user_profile){
    char *categories[NUM_OF_CATEGORIES] = {"Business", "Samfund", "Sundhed og Mennesker", "Kreativ", "Informationsteknologi", "Videnskab"};

    printf(BOLD"\nChoose ONE of the following five categories in which you are most interested in\n"SET_TEXT_DEFAULT);
    for (int i = 0; i < NUM_OF_CATEGORIES; i++){
        printf("\n  %s",categories[i]);
    }
    printf("\n");

    int valid_category_input = 0;
     while(valid_category_input != 1){
        char user_category[100];
        printf(BOLD"\nWhich category are you most interested in? \n"SET_TEXT_DEFAULT);
        scanf(" %s", user_category);
        // Sammenligner brugerens input med en predefineret liste af fag
        // for at validere om det er et gyldigt input.
        int category_validation = categoryDecider(user_category);
        if (category_validation != -1){
            user_profile->category = category_validation;
            valid_category_input = 1;
        } else {
            printf(RED BOLD"Invalid category, please try again.\n"SET_TEXT_DEFAULT);
        }
    }
    printf("%d", user_profile->category);
}
    
// Sammenligner strings med henblik på at returnere en integer værdi tildelt kategorien
int categoryDecider(char* user_category){
    // Konverterer user_category til uppercase
    toUpperCase(user_category);
    if (strcmp(user_category, "BUSINESS") == 0){
        return BUSINESS;
    } else if (strcmp(user_category, "SAMFUND") == 0){
        return SAMFUND;
    } else if (strcmp(user_category, "INFORMATIONSTEKNOLOGI") == 0){
        return INFORMATIONSTEKNOLOGI;
    } else if (strcmp(user_category, "VIDENSKAB") == 0){
        return VIDENSKAB;
    } else if (strcmp(user_category, "SUNDHED OG MENNESKER") == 0){
        return SUNDHED_OG_MENNESKER;
    } else if (strcmp(user_category, "KREATIV") == 0){
        return KREATIV;
    } else {
        return -1; //Ukendt kategori
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