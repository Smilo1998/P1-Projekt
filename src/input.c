#include "../include/header.h" 
#include "../include/input.h"
#include "../include/toolbox.h" 

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean vaerdi i et struct student_profile
student_profile addStudent(void){
    student_profile user_profile;

    inputGPA(&user_profile);
    // Prompter og gemmer de fag brugeren har haft i et array
    subjectInput(&user_profile);
  
    subjectRating(&user_profile);

    statementRating(&user_profile);

    categoryRating(&user_profile);

    return user_profile;
}  

void inputGPA(student_profile *user_profile){
int valid_gpa_input = 0;
double user_input_gpa = 0;
    // While-loekken gentager indtil brugeren indtaster et gyldigt input. 
    // Fungerer som fejlsirking mod stavefejl eller ugyldigt input. 
    while(!valid_gpa_input){
        printf(BOLD"\nIndtast dit karaktergennemsnit: "SET_TEXT_DEFAULT);
            // Tjekker at input er gyldigt
            if (getInputDecimal(&user_input_gpa) == true){ // Modtager et float-input 
                if (user_input_gpa >= 0 && user_input_gpa <= 13){
                    user_profile->gpa = user_input_gpa;
                    valid_gpa_input = 1;
                } else {
                    printf(RED BOLD "Karaktergennemsnittet skal vaere et tal mellem 0-13!\n" SET_TEXT_DEFAULT);
                }
            }
        clearBuffer();
    }
}

// Spoerger efter hvert fag og svaret modtages i A, B, C eller 0. 
// Derefter omdannes det henholdvis til enum-vaerdierne 1, 2, 3 eller 0 og gemmes i brugerens fag_array
void subjectInput(student_profile *user_profile){
    int i;
    char* subjects_print[10] = {"Matematik", "Fysik", "Kemi", "Biologi", "Dansk", "Engelsk", "Historie",
                                "Samfundsfag", "Virksomhedsoekonomi", "Afsaetning"};
    int valid_level_input = 0;
    char temp[MAX_USER_INPUT_LENGTH + 1];

    printf(BOLD"\nIndtast det niveau du har gennemfoert faget paa (A, B eller C). Indtast 0 hvis du ikke har gennemfoert faget.\n"SET_TEXT_DEFAULT);
    
    for(i = 0; i < NUM_OF_SUBJECTS; i++){
        valid_level_input = 0; // Nulstilles for at gentage loekken ved hver iteration.
        
        // While-loekken gentager, indtil brugeren indtaster et gyldigt input.
        // Fungerer som fejlsirking mod stavefejl eller ugyldigt input. 
        while(!valid_level_input){ // Loekke til at sikre gyldigt input
            printf("\n%s: ", subjects_print[i]);
            if (getInputString(temp) == true){ // Modtager et string-input
                // Konverterer input til store bogstaver for at undgaa problemer med casing-forskelle under validation.
                // Tjekker at input enten er A, B, C eller 0 ved brug af strcmp() funktionen fra string.h biblioteket.
                // Og tildeler det til faget,
                if (strcmp(temp, "A") == 0) {
                    user_profile->fag_array[i] = A;
                    valid_level_input = 1;
                } else if (strcmp(temp, "B") == 0) {
                    user_profile->fag_array[i] = B;
                    valid_level_input = 1;
                } else if (strcmp(temp, "C") == 0) {
                    user_profile->fag_array[i] = C;
                    valid_level_input = 1;
                } else if (strcmp(temp, "0") == 0) {
                    user_profile->fag_array[i] = 0;
                    valid_level_input = 1;
                } else {
                    printf(RED BOLD"Du skal indtaste et gyldigt niveau eller 0!\n" SET_TEXT_DEFAULT);
                }
            }
        clearBuffer(); // Rydder inputbufferen
        }     
    }
}

void subjectRating(student_profile *user_profile){
    int i;
    char* subjects_print[10] = {"Matematik", "Fysik", "Kemi", "Biologi", "Dansk", "Engelsk", "Historie",
                                "Samfundsfag", "Virksomhedsoekonomi", "Afsaetning"};
    int valid_subject_rating_input = 0;
    int temp;

    printf(BOLD"\nBedoem fra 1-5 hvor meget du kunne lide dine fag\n" SET_TEXT_DEFAULT);
    for (i = 0; i < NUM_OF_SUBJECTS; i++){
        valid_subject_rating_input = 0;
        while(!valid_subject_rating_input){ // Loekke til at sikre gyldigt input
            if(user_profile->fag_array[i] != 0){ // Tjekker om brugeren ratede '0' tidligere, saa faget skippes hvis det ikke er taget.
                printf("\n%s: ", subjects_print[i]);
                if (getInputInt(&temp) == true){ // Modtager et integer-input
                    if (temp >= 1 && temp <= 5){
                        user_profile->subject_rating[i] = temp;
                        valid_subject_rating_input = 1;
                    } else {
                        printf(RED BOLD"Ugyildigt! Du skal indtaste en bedoemmelse mellem 1-5!\n"SET_TEXT_DEFAULT);
                    }
                }    
                clearBuffer(); // Rydder inputbufferen
            } else {
                user_profile->subject_rating[i] = 0;
                valid_subject_rating_input = 1;
            }
        }
    }
}

// Funktion til at print en raekke udsagn, som brugeren skal rate fra 1-5
void statementRating(student_profile *user_profile){
    int i, j, k, q, z;
    char *statement_print[NUM_OF_STATEMENTS] = {"A) Jeg prioriterer en hoej loen", "B) Jeg prioriterer arbejde med mennesker", "C) Jeg prioriterer fleksible arbejdstider",
                                                "D) Jeg prioriterer gode beskaeftigelsesmuligheder", "E) Jeg prioriterer passion for mit arbejde"};
    char statement_id[NUM_OF_STATEMENTS] = {'A', 'B', 'C', 'D', 'E'};
    int valid_statement_rating_input = 0;
    char temp[MAX_USER_INPUT_LENGTH + 1];
    int already_rated[NUM_OF_STATEMENTS] = {0, 0, 0, 0, 0};
    int valid_redo_input = 0;
    char redo_temp[MAX_USER_INPUT_LENGTH + 1];
    int confirmStatements = 0;
    // Denne while-loekke bruges til at gentage kodeblokken til statement rating, 
    // i tilfaelde af at brugeren vaelger "Redo" muligheden senere
    while(!confirmStatements){ // Loekke til at sikre gyldigt input
        valid_redo_input = 0;
        printf(BOLD"\nTildel de foelgende udsagn, ved hjaelp af A, B, C, D eller E, en prioritet i raekkefoelge efter hvor vigtige de er for dig:\n"SET_TEXT_DEFAULT);
        // For-loop printer udsagnene der blev defineret tidligere i statement_print
        for (i = 0; i < NUM_OF_STATEMENTS; i++){
            printf("\n  %s",statement_print[i]);
        }
        printf(BOLD "\n\nDu kan kun tildele EN ENKEL prioritering til hvert udsagn for at prioritere\n" SET_TEXT_DEFAULT);
        for (j = 0; j < NUM_OF_STATEMENTS; j++){
            valid_statement_rating_input = 0;
            while(!valid_statement_rating_input){   // Loekke til at sikre gyldigt input
                printf("\n%d prioritet: ", j + 1);
                
                if (getInputString(temp) == true){ // Modtager et string-input
                    // Tjekker om temp kun har et tegn og bruger strchr til at tjekke om det er A, B, C, D eller E.
                    if (strlen(temp) == 1 && strchr("ABCDE", temp[0]) != NULL) { 
                        // For-loekke til at tjekke hvilken af statement_id's som det indtastede char matcher.
                        for (k = 0; k < NUM_OF_STATEMENTS; k++){
                            if (temp[0] == statement_id[k]){
                                // Tjekker om den statement allerede er rated ellers fejlbesked.
                                if (already_rated[k] == 0){
                                    // + 1, saa de endelige integers i arrayet stemmer overens med 1-5, som i "prioritet 1-5", i stedet for 0-4.
                                    // I teorien overfloedigt, men skaber bedre laesbarhed.
                                    user_profile->statement_rating[j] = k + 1;
                                    already_rated[k]++; // Inkrementerer for at taelle at denne statement nu er rated en gang.
                                    valid_statement_rating_input = 1;
                                    break;  
                                } else {
                                    // Fejlbesked hvis indexet i already_rated ikke er 0, som indikerer at den allerede er rated
                                    printf(RED BOLD"Du har allerede tildelt det udsagn en prioritet!\n"SET_TEXT_DEFAULT);
                                }
                            }
                        }
                    } else {
                    printf(RED BOLD"Ugyldigt input! Du skal bruge A, B, C, D eller E for at tildele en prioritet!\n"SET_TEXT_DEFAULT);
                    }
                }
                clearBuffer(); // Rydder inputbufferen
            }
        }
        printf(BOLD"\nDu har prioriteret udsagnene i den foelgende raekkefoelge:\n\n"SET_TEXT_DEFAULT);
        for(q = 0; q < NUM_OF_STATEMENTS; q++){
            printf(BOLD"%d prioritet: "SET_TEXT_DEFAULT, q + 1);
            // - 1 saa det stemmer med indexerne i statement_print, fordi vi +'ede med 1 tidligere for laesbarheden af prioriteterne.
            printf("%s\n",statement_print[user_profile->statement_rating[q] - 1]);
        }
        while(!valid_redo_input){ // Loekke til at sikre gyldigt input
            printf(BOLD"\nIndtast Y for at bekraefte eller R for at lave raekkefoelgen om\n"SET_TEXT_DEFAULT);
                
            if (getInputString(redo_temp) == true){ // Modtager et string-input
                // Tjekker om temp kun har et tegn og bruger strchr til at tjekke om det er Y eller R.
                if (strlen(redo_temp) == 1 && strchr("YR", redo_temp[0]) != NULL){
                    // Hvis 'Y' lukkes baade confirmStatements og valid_redo_input loekken saa at programmet fortsaetter.
                    if (redo_temp[0] == 'Y'){
                        confirmStatements = 1;
                        valid_redo_input = 1;
                        break;
                    // Hvis 'R' lukkes kun valid_redo_input loekken for at programmet gentager prioriterings-blokken.
                    } else if (redo_temp[0] == 'R'){
                        // Restarter indexerne i statement_rating og already_rated til henholdvis -1 og 0 for at undgaa fejl, naar de bruges igen.
                        for (z = 0; z < NUM_OF_STATEMENTS; z++) {
                            user_profile->statement_rating[z] = -1;
                            already_rated[z] = 0;
                        }
                        valid_redo_input = 1;
                        break;
                    }
                }
                else {
                    printf(RED BOLD"Ugyldigt input!"SET_TEXT_DEFAULT);
                }
            }
            clearBuffer(); // Rydder inputbufferen
        }    
    }
}

void categoryRating(student_profile *user_profile){
    char *categories[NUM_OF_CATEGORIES] = {"Business", "Samfund", "Sundhed/Mennesker", "Kreativ", "Informationsteknologi", "Videnskab"};

    printf(BOLD"\nVaelg EN af de foelgende fem kategorier som du er mest interesseret i:\n"SET_TEXT_DEFAULT);
    for (int i = 0; i < NUM_OF_CATEGORIES; i++){
        printf("\n  %s",categories[i]);
    }
    printf("\n");

    int valid_category_input = 0;
    while(valid_category_input != 1){ // Loekke til at sikre gyldigt input
        char user_category[MAX_USER_INPUT_LENGTH + 1];

        printf(BOLD"\nHvilken kategori er du mest interesseret i? \n"SET_TEXT_DEFAULT);
        printf("(Du vaelger ved at indtaste navnet paa kategorien) \n\n");
        
        if (getInputString(user_category) == true){ // Modtager et string-input
            // Sammenligner brugerens input med en predefineret liste af fag
            // for at validere om det er et gyldigt input.
            int category_validation = categoryDecider(user_category);
            if (category_validation != -1){
                user_profile->category = category_validation;
                printf("%d",category_validation);
                valid_category_input = 1;
            } else {
                printf(RED BOLD"Ugyldig kategori, proev igen!\n"SET_TEXT_DEFAULT);
            }
        }
        clearBuffer();
    }
}
    
// Sammenligner strings med henblik på at returnere en integer værdi tildelt kategorien
int categoryDecider(char* user_category){
    if (strcmp(user_category, "BUSINESS") == 0){
        return BUSINESS;
    } else if (strcmp(user_category, "SAMFUND") == 0){
        return SAMFUND;
    } else if (strcmp(user_category, "INFORMATIONSTEKNOLOGI") == 0){
        return INFORMATIONSTEKNOLOGI;
    } else if (strcmp(user_category, "VIDENSKAB") == 0){
        return VIDENSKAB;
    } else if (strcmp(user_category, "SUNDHED/MENNESKER") == 0){
        return SUNDHED_OG_MENNESKER;
    } else if (strcmp(user_category, "KREATIV") == 0){
        return KREATIV;
    } else {
        return -1; //Ukendt kategori
    }
}