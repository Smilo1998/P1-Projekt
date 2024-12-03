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

void getStudents(student_profile profiles[], educations education_choice_array[]){
    int i, j, k, q;
    char subject[SUBJECT_NAME+1];
    char education[60];

    FILE *student_file = fopen("../datafiles/student.txt", "r");
    if (student_file == NULL) {
        printf("Could not open file.\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < NUM_OF_STUDENTS; i++){
        fscanf(student_file, " %lf", &profiles[i].gpa);
        for(j = 0; j < NUM_OF_SUBJECTS; j++){
            fscanf(student_file, "%d", &profiles[i].fag_array[j]);
        }
        for(q = 0; q < NUM_OF_SUBJECTS; q++){
            fscanf(student_file, "%d", &profiles[i].subject_rating[q]);
        }

        fscanf(student_file, "%s", subject);
        profiles[i].favorite_subject = favoriteSubjectDecider(subject);

        fscanf(student_file, " %[^\n]", education);

        for(k = 0; k < MAX_EDUCATIONS; k++){
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
    for(i = 0; i < MAX_EDUCATIONS; i++){
        fscanf(education_file, " %[^\n]", education_choice[i].name);
        for(j = 0; j < NUM_OF_SUBJECTS; j++){
            fscanf(education_file, "%lf", &education_choice[i].min_grade[j]);
        }
        fscanf(education_file, "%s", education_choice[i].link);
    }
    fclose(education_file);
}