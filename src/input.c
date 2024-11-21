#include "../include/header.h" 

// Funktion som tager input fra bruger og gemmer gpa og fag-boolean vaerdi i et struct student_profile
student_profile addStudent(void){
    student_profile user_profile;
    char user_subject[SUBJECT_NAME];
    int valid_subject = 0;
    int valid_gpa = 0;

    // Prompter efter brugers karaktergennemsnit
    while(!valid_gpa){
        printf("Enter your grade average: ");
        
        if ((scanf(" %lf", &user_profile.gpa) == 1) && user_profile.gpa >= 0 && user_profile.gpa <= 13){
            valid_gpa = 1;
        }else{
            printf("Invalid GPA!\n");
            //Dette rydder inputbufferen for at komme af med eventuelle forkert inputs som bogstaver og andre symboler end doubles.
            while(getchar() != '\n');
        }
        
    }
    // Prompter og gemmer de fag brugeren har haft i et boolean array
    subjectInput(&user_profile);
    
    // While-loekken koerer indtil der indtastes et gyldigt fag. Fungerer som fejlsirking mod stavefejl eller ugyldigt bruger-input. 
    while(!valid_subject){
        // Prompter efter brugerens yndlingsfag
        printf("What is your favorite subject? \n");
        scanf("%s", user_subject);

        int subjectValidation = favoriteSubjectDecider(user_subject);
        if (subjectValidation != -1){
            user_profile.favorite_subject = subjectValidation;
            valid_subject = 1;
        } else {
            printf("Invalid subject. Type the subjects name in danish.\n");
        }
    }
    return user_profile;
}  

//Spoerger efter hvert fag og svaret modtages i 1 eller 0 for at goere det nemmere i fremtiden. kan altid aendres.
void subjectInput(student_profile *user_profile){
    int i;
    char* subjects_print[10];
    int valid_binary_input = 0;
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

    // Prompter brugeren til at skrive 
    printf("Type the level of which you completed the subject (A, B or C. 0 if not completed).");
    
    for(i = 0; i < 10; i++){
        //Saettes tilbage til 0 ved start at hver iteration for at loekken kan koere igen.
        valid_binary_input = 0;
  
        // While-loekken koerer indtil der indtastes et gyldigt input (0 eller 1). Fungerer som fejlsirking mod ugyldigt bruger-input.
        while(!valid_binary_input){

            printf("\n%s: ", subjects_print[i]);
            scanf(" %4s", temp);
            
            if (strcmp(temp, "A") == 0 || strcmp(temp, "a") == 0) {
                user_profile->fag_array[i] = A;
                valid_binary_input = 1;
            } else if (strcmp(temp, "B") == 0 || strcmp(temp, "b") == 0) {
                user_profile->fag_array[i] = B;
                valid_binary_input = 1;
            } else if (strcmp(temp, "C") == 0 || strcmp(temp, "c") == 0) {
                user_profile->fag_array[i] = C;
                valid_binary_input = 1;
            } else if (strcmp(temp, "0") == 0) {
                user_profile->fag_array[i] = 0;
                valid_binary_input = 1;
            } else{
                printf("Invalid Input!\n");
            }  
            // Clearer input buffer
            while(getchar() != '\n');    
        } 
    }
}

//Tager et char array som input og gennemgaar hvert index og konverterer det til et Uppercase bogstav
//Det goer den ved brug af toupper() funktionen fra ctype.h biblioteket, som omdanner smaa bogstaver til store bogstaver.
void toUpperCase (char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
}

int favoriteSubjectDecider(char* user_subject){ 
    // Konverterer user_subject til store bogstaver foer sammenligning, for at fejlsikre mod case-forskelle.
    toUpperCase(user_subject); 

    //Sammenligner den upperCase konverteret version af user_subject med en raekke forskellige fag.
    //Hvis der er et match, returneres den tilsvarende enum vaerdi for det paagaeldende fag. Ellers returneres -1
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





