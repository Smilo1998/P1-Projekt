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
void getStudentProfiles(student_profile profiles[]){

    profiles[0] = (student_profile) {
        .gpa = 6.78,
        .fag_array = {1, 1, 1, 0, 1, 1, 0, 0, 0, 0,},
        .favorite_subject = MATEMATIK,
        .education_choice = "Fysik og Ingenioervidenskab"
    };

    profiles[1] = (student_profile) {
        .gpa = 8.36,
        .fag_array = {1, 0, 0, 0, 1, 1, 1, 1, 0, 0}, // 5
        .favorite_subject = SAMFUNDSFAG,
        .education_choice = "Statskundskab"
    };
    profiles[2] = (student_profile)
    {
        .gpa = 7.87,
        .fag_array = {1, 0, 0, 0, 1, 1, 0, 0, 1, 1}, // 1
        .favorite_subject = AFSAETNING,
        .education_choice = "Erhvervsoekonomi"
    };
}
  