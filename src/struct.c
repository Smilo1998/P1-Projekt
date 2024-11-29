#include "../include/header.h"

/*  INDEKSPLADSER FOR FAGENE i array nedenunder
    MATEMATIK = 0,
    FYSIK = 1,
    KEMI = 2,
    BIOLOGI = 3,
    DANSK = 4,
    ENGELSK = 5,
    HISTORIE = 6,
    SAMFUNDSFAG = 7,
    VIRKSOMHEDSOEKONOMI = 8,
    AFSAETNING = 9,
*/

// Funktion som genererer kunstige personer som har valgt en bestemt uddannelse
/*
void getStudentProfiles(student_profile profiles[], educations education_choice_array[]){
    
    profiles[0] = (student_profile) {
        .gpa = 9.43,
        .fag_array = {3, 3, 2, 2, 3, 3, 3, 1, 0, 0,},
        .favorite_subject = MATEMATIK,
        .education_choice = education_choice_array[3],
    };

    profiles[1] = (student_profile) {
        .gpa = 11.2,
        .fag_array = {2, 1, 1, 1, 3, 3, 3, 3, 0, 0}, 
        .favorite_subject = SAMFUNDSFAG,
        .education_choice = education_choice_array[2],
    };
    profiles[2] = (student_profile)
    {
        .gpa = 7.87,
        .fag_array = {2, 0, 0, 0, 3, 3, 2, 2, 3, 3}, 
        .favorite_subject = AFSAETNING,
        .education_choice = education_choice_array[1],
    };
}
*/

// Funktion som generer uddannelser 
/*
void getEducationData(educations education_choice[]){

    education_choice[0] = (educations) {
        .name = {"Software AAU"},
        .min_grade = {5.4, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        .city = {1, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        .link = {"https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/tekniskvidenskabeligebacheloruddannelser/civilingenioeruddannelser/software"},
    };
    education_choice[1] = (educations) {
        .name = {"Erhvervsoekonomi, HA"},
        .min_grade = {7.9, 7.9, 6.7, 2, 2, 0, 0, 2, 0, 6},
        .city = {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
        .link = {"https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/samfundsvidenskabeligebacheloruddannelser/erhvervsoekonomi/erhvervsoekonomi-ha"},
    };
    education_choice[2] = (educations) {
        .name = {"Statskundskab"},
        .min_grade = {10.5, 8.9, 9.0, 0, 0, 0, 0, 0, 0, 0},
        .city = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        .link = {"https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/samfundsvidenskabeligebacheloruddannelser/forvaltningmv/statskundskab"},
    };
    education_choice[3] = (educations) {
        .name = {"Fysik og ingenioervidenskab"},
        .min_grade = {8.4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .city = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .link = {"https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/tekniskvidenskabeligebacheloruddannelser/civilingenioeruddannelser/fysik-og-ingenioervidenskab"},
    };   
}*/

void getStudents(student_profile profiles[], educations education_choice_array[]){
    int i, j, k;
    char subject[SUBJECT_NAME+1];
    char education[60];

    FILE *student_file = fopen("../datafiles/student.txt", "r");
    if (student_file == NULL) {
        printf("Could not open file.\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < 3; i++){
        fscanf(student_file, " %lf", &profiles[i].gpa);
        for(j = 0; j < 10; j++){
            fscanf(student_file, "%d", &profiles[i].fag_array[j]);
        }
        fscanf(student_file, "%s", subject);
        profiles[i].favorite_subject = favoriteSubjectDecider(subject);

        fscanf(student_file, " %[^\n]", education);

        for(k = 0; k < 4; k++){
            if(strcmp(education, education_choice_array[k].name) == 0){
                profiles[i].education_choice = education_choice_array[k];
            }
        }
    }
    fclose(student_file);
}

void getEducations(educations education_choice[]){
    int i;
    int j;

    FILE *education_file = fopen("../datafiles/education.txt", "r");
    if (education_file == NULL) {
        printf("Could not open file.\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < 4; i++){
        fscanf(education_file, " %[^\n]", education_choice[i].name);
        for(j = 0; j < 10; j++){
            fscanf(education_file, "%lf", &education_choice[i].min_grade[j]);
        }
        fscanf(education_file, "%s", education_choice[i].link);
    }
    fclose(education_file);
}







  