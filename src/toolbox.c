#include "../include/header.h" 
#include "../include/toolbox.h"

bool standardUserInputValidation(char* user_input){
    if (scanf(" %25[^\n]", user_input) == 1 && !extraInput()){
        toUpperCase(user_input);
        return true;
    } else if (extraInput()) {
        printf(RED BOLD "Input too long! Maximum of 25 characters!\n\n" SET_TEXT_DEFAULT);
        return false;
    }
}

bool getInputDecimal(double* decimal){
    char user_input[MAX_USER_INPUT_LENGTH + 1];
    char temp[MAX_USER_INPUT_LENGTH + 1];
    int decimal_seperator_count = 0;

    if (standardUserInputValidation(user_input) == true) {        
        if (sscanf(user_input, "%25[0-9,.]", temp) == 1 && strlen(user_input) == strlen(temp)) {
            for (int i = 0; i < strlen(temp); i++) {
                if (temp[i] == ',' || temp[i] == '.'){
                    temp[i] = '.';
                    decimal_seperator_count += 1;
                } 
            }
            if (decimal_seperator_count <= 1){
                *decimal = atof(temp);
                return true; 
            } else {
                printf(RED BOLD "Please only use a single decimal seperator!\n\n" SET_TEXT_DEFAULT);
                return false;
            }    
        } else {
            printf(RED BOLD "You can only use numbers and either . or , to seperate the decimal!\n\n" SET_TEXT_DEFAULT);
            return false;
        }
    } else {
        return false;
    }
} 

bool getInputInt(int* integer){
    char user_input[MAX_USER_INPUT_LENGTH + 1];
    char temp[MAX_USER_INPUT_LENGTH + 1];

    if (standardUserInputValidation(user_input) == true) {        
        if (sscanf(user_input, "%25[0-9]", temp) == 1 && strlen(user_input) == strlen(temp)) {
            *integer = atoi(temp);
            return true; 
        } else {
            printf(RED BOLD "You can only use numbers!\n\n" SET_TEXT_DEFAULT);
            return false;
        }
    } else {
        return false;
    }
}  

bool getInputString(char* string){
    bool successful_input = false;

    successful_input = standardUserInputValidation(string);
    if (successful_input == true){
        return true;
    } else {
        return false;
    }
}




// Rydder inputbufferen ved at laese og kassere alle tegn indtil ('\n') som markerer at inputbufferen er tom.
// Dette sikrer, at eventuelle resterende tegn i inputbufferen fra forkerte inputs ikke paavirker det efterfoelgende input.
void clearBuffer(){
    while(getchar() != '\n'); 
}

// Tager et char array som input og konverterer hvert index til et Uppercase.
// Det goeres ved brug af toupper() funktionen fra ctype.h biblioteket, som omdanner smaa bogstaver til store bogstaver.
// toupper() tager kun et enkelt char som input, derfor er et for-loop noedvendigt for at konvertere hele char arrays.
void toUpperCase (char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        str[i] = toupper(str[i]);
    }
}

void resetIntArray(char arrayToReset[]){
    int sizeOfArray = strlen(arrayToReset);
    for (int i = 0; i < sizeOfArray; i++) {
        arrayToReset[i] = 0;
    }
}

int containsSpaces(char arrayToCheck[]) {
    if (strchr(arrayToCheck, ' ') != NULL){
        return 1;
    } else {
        return 0;
    }
}

int extraInput() {
    int bufferCheck = fgetc(stdin);
    // printf("%d\n",bufferCheck);
    if (bufferCheck == '\n') {
        ungetc(bufferCheck, stdin);
        return 0;
    }
    ungetc(bufferCheck, stdin);
    return 1;
}