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
void getStudentProfiles(student_profile profiles[], educations education_choice_array[]){

    profiles[0] = (student_profile) {
        .gpa = 9.43,
        .fag_array = {3, 3, 2, 2, 3, 3, 3, 1, 0, 0,},
        .favorite_subject = MATEMATIK,
        .education_choice = education_choice_array[3],
    };

    profiles[1] = (student_profile) {
        .gpa = 11.2,
        .fag_array = {2, 1, 1, 1, 3, 3, 3, 3, 0, 0}, // 5
        .favorite_subject = SAMFUNDSFAG,
        .education_choice = education_choice_array[2],
    };
    profiles[2] = (student_profile)
    {
        .gpa = 7.87,
        .fag_array = {2, 0, 0, 0, 3, 3, 2, 2, 3, 3}, // 1
        .favorite_subject = AFSAETNING,
        .education_choice = education_choice_array[1],
    };
}

void getEducationData(educations education_choice[]){

    education_choice[0] = (educations) {
        .name = {"Software AAU"},
        .min_grade = {5.4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        .city = {1, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        .link = {"https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/tekniskvidenskabeligebacheloruddannelser/civilingenioeruddannelser/software"},
    };
    education_choice[1] = (educations) {
        .name = {"Erhvervsoekonomi, HA"},
        .min_grade = {7.9, 7.9, 6.7, 0, 0, 0, 0, 0, 0, 6},
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
}







  