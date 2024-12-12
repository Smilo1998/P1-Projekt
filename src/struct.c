#include "../include/header.h"
#include "../include/struct.h"

//Funktion der scanner elevprofiler fra student.txt ved brug af fscanf.
//Dataen bliver scannet ind i et array af struct student_profile
void getStudents(student_profile profiles[], educations education_choice_array[]){
    int i, j, q, g, k;
    char education[NAME_LENGTH];

    // Initilisering af en file pointer til en txt fil
    FILE *student_file = fopen("../datafiles/student.txt", "r");
    //Error handling hvis fil ikke kan åbnes.
    if (student_file == NULL) {
        printf("Could not open file.\n");
        exit(EXIT_FAILURE);
    }
    //Itererer over hver student i student.txt
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        //scanner gpa ind som double
        fscanf(student_file, "%lf", &profiles[i].gpa);
        //scanner en liste af fag niveauer ind i et array
        for(j = 0; j < NUM_OF_SUBJECTS; j++){
            fscanf(student_file, "%d", &profiles[i].fag_array[j]);
        }
        //scanner en liste af interesse for fag ind i et array
        for(q = 0; q < NUM_OF_SUBJECTS; q++){
            fscanf(student_file, "%d", &profiles[i].subject_rating[q]);
        }
        //scanner dataen om statement ratings ind i et array
        for(g = 0; g < NUM_OF_STATEMENTS; g++){
            fscanf(student_file, "%d", &profiles[i].statement_rating[g]);
        }
        //scanner kategori interesse ind i struct student_profile
        fscanf(student_file, "%d", &profiles[i].category);        
        //Scanner studentens valgte uddannelse ind.
        fscanf(student_file, " %[^\n]", education);
        //Tjekker om navnet af uddannelsesvalget stemmer overens med en uddannelse fra education_choice_array
        for(k = 0; k < MAX_EDUCATIONS; k++){
            if(strcmp(education, education_choice_array[k].name) == 0){
                profiles[i].education_choice = education_choice_array[k];
                printf("%s --- %s\n", education, education_choice_array[k].name);
                break;
            }
        }
        
    }
    fclose(student_file); 
}

//Funktion der scanner uddannelser fra education.txt ved brug af fscanf.
//Dataen bliver printet ind i et array af struct educations
void getEducations(educations education_choice[]){
    int i;
    int j;

    FILE *education_file = fopen("../datafiles/education.txt", "r");
    //Error handling hvis fil ikke kan åbnes.
    if (education_file == NULL) {
        printf("Could not open file.\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < MAX_EDUCATIONS; i++){
        // Scanner efter uddannelsesnavn indtil linjeskift
        fscanf(education_file, " %[^\n]", education_choice[i].name);
        // Scanner efter et array af karakterkrav ud fra byerne uddannelserne er tilgængelige i indtil MAX_CITY
        for(j = 0; j < MAX_CITY; j++){
            fscanf(education_file, "%lf", &education_choice[i].min_grade[j]);
        }
        // Scanner et link som en string
        fscanf(education_file, "%s", education_choice[i].link);
    }
    fclose(education_file);
}