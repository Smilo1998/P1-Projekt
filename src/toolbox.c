#include "../include/header.h" 
#include "../include/toolbox.h"

// Funktion til at laese alt input fra brugeren.
// Laeser op til 25 tegn fra brugeren, med en scanmap der ignorerer forudgaaende hvidt-tegn og stopper ved newline.
// Konverterer alt input til uppercase, med toUpperCase(), for at forhinde fejl med case-forskelle.
// Skaber en maade at laese alle former for input ogsaa med mellemrum.
// Yderligere tjek og errorhandling udfoeres i de individuelle getInput-funktioner.
// Goer brug af extrainput() for at tjekke om der indtastes mere end 25 tegn.
// Returnerer en bool i form af true eller false, alt efter om inputtet blev succesfuldt behandlet.
bool standardUserInputValidation(char* user_input){
    if (scanf(" %25[^\n]", user_input) == 1 && !extraInput()){
        toUpperCase(user_input);
        return true;
    } else if (extraInput()) {
        printf(RED BOLD "Input er for langt! Maksimum af 25 tegn!\n" SET_TEXT_DEFAULT);
        return false;
    }
    return false;
}

// Funktion til at validere og behandle input som et decimaltal. Tager et gyldigt input fra standardUserInputValidation og 
// tillader kun tal mellem 0-9 og '-' til at indikere et negativt tal og ',' eller '.' som decimalseparatorer. 
// Derneast konverteres alle ',' til '.'. Til sidst omdannes stringen til en float ved hjaelp af 'atof' funktionen.
// Returnerer en bool i form af true eller false, alt efter om inputtet blev succesfuldt behandlet.  
bool getInputDecimal(double* decimal){
    char user_input[MAX_USER_INPUT_LENGTH + 1];
    char temp[MAX_USER_INPUT_LENGTH + 1];
    int decimal_separator_count = 0;
    int sign_count = 0;

    if (standardUserInputValidation(user_input) == true) {     
        // Bruger strlen for at sammenligne laengden af user_input fra standardUserInputValidation og temp.
        // Da scanmap ellers stopper saa snart den laeser noget der ikke er en af tegnene den inkluderer. 
        // Saa hvis user_input er laengere end temp, indikerer det at der er andre tegn end [-0-9,.] i den.
        // Caster strlen() til int, saa den returnerer en vaerdi som int istedet for size_t.
        if (sscanf(user_input, "%25[-+0-9,.]", temp) == 1 && strlen(user_input) == strlen(temp)) {
            for (int i = 0; i < (int)strlen(temp); i++) {
                if (temp[i] == ',' || temp[i] == '.'){
                    temp[i] = '.';
                    decimal_separator_count += 1; // Taeller om der er flere decimalseparatorer for at invalidere input som "5.7.3.2".
                } else if (temp[i] == '+' || temp[i] == '-'){
                    sign_count += 1; // Taeller om der er flere fortegn for at invalidere input som "-5.2+2-3".
                }
            }
            if (decimal_separator_count <= 1 && sign_count <= 1){
                *decimal = atof(temp);
                return true; 
            } else if (decimal_separator_count > 1){
                printf(RED BOLD "Brug venligst kun en enkelt decimalseparator!\n" SET_TEXT_DEFAULT);
                return false;
            } else {
                printf(RED BOLD "Brug venligst kun et enkelt +/- fortegn!\n" SET_TEXT_DEFAULT);
                return false;
            }    
        } else {
            printf(RED BOLD "Du kan kun bruge tal og enten . eller , som decimalseparator!\n" SET_TEXT_DEFAULT);
            return false;
        }
    } else {
        return false;
    }
} 

// Funktion til at faa et input af en integer. Fungerer paa samme maade som getInputDecimal, men ikke med konvertering af ',' til '.'.
// Og bruger atoi i stedet for atof, for at konvertere string til integer.
// Returnerer en bool i form af true eller false, alt efter om inputtet blev succesfuldt behandlet. 
bool getInputInt(int* integer){
    char user_input[MAX_USER_INPUT_LENGTH + 1];
    char temp[MAX_USER_INPUT_LENGTH + 1];
    int sign_count = 0;

    if (standardUserInputValidation(user_input) == true) {        
        if (sscanf(user_input, "%25[-+0-9]", temp) == 1 && strlen(user_input) == strlen(temp)) {
            for (int i = 0; i < (int)strlen(temp); i++){
                if (temp[i] == '+' || temp[i] == '-'){
                    sign_count += 1; // Taeller om der er flere fortegn for at invalidere input som "-5-2+5-7".
                }
            }
            if (sign_count <= 1){
                *integer = atoi(temp);
                return true; 
            } else {
                printf(RED BOLD "Brug venligst kun et enkelt +/- fortegn!\n" SET_TEXT_DEFAULT);
                return false;
            } 
        } else {
            printf(RED BOLD "Du kan kun bruge heltal!\n" SET_TEXT_DEFAULT);
            return false;
        }
    } else {
        return false;
    }
}  

// Standard funktion til at faa et input af en string. Der er ikke yderligere tjek i dette tilfaelde da standardUserInputValidation
// i forvejen tager en string som standard input.
// Returnerer en bool i form af true eller false, alt efter om inputtet blev succesfuldt behandlet. 
bool getInputString(char* string){

    if (standardUserInputValidation(string) == true){
        return true;
    } else {
        return false;
    }
}

// Rydder inputbufferen ved at laese og kassere alle tegn indtil '\n' som markerer at inputbufferen er tom.
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

// Tjekker om der er eksta input tilbage i stdin-bufferen, ved brug af fgetc. Sammenligner om det er '\n',
// hvilket ville indikere en tom buffer. 0 eller 1 returneres henholdsvis om bufferen er tom eller ej.
// Tegnet saettes tilbage i bufferen med ungetc for ikke at skabe problemer med efterfoelgnde clearbuffer kald.
// Det ville ellers "dobbeltryde" bufferen, som ville skabe en pause i programmet.
int extraInput() {
    // buffercheck er en int og ikke en char fordi at fgetc returnerer ikke selve tegnet den finder, men ASCII-koden for det tegn, som er en int.
    int bufferCheck = fgetc(stdin);
    if (bufferCheck == '\n') {
        ungetc(bufferCheck, stdin);
        return 0;
    }
    ungetc(bufferCheck, stdin);
    return 1;
}