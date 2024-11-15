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
void getStruct(){
    student_profile student_array[MAX_DATA];
    student_array[0]  = {{1, 0, 0, 1, 1, 1, 1, 1, 0, 0}, "Samfundsfag", "Statskundskab"};
    student_array[1]  = {{1, 1, 1, 0, 1, 0, 0, 0, 1, 1}, "Matematik", "Forsikringsmatematik"};
    student_array[2]  = {{1, 0, 0, 0, 1, 1, 1, 0, 1, 1}, "Virksomhedsoekonomi", "Erhvervsoekonomi"};
    student_array[3]  = {{0, 1, 1, 1, 0, 0, 1, 0, 1, 0}, "Historie", "Historie og Kultur"};
    student_array[4]  = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, "Dansk", "Dansk"};
    student_array[5]  = {{1, 0, 1, 0, 1, 0, 0, 1, 1, 0}, "Afsaetning", "Markedsfoering"};
    student_array[6]  = {{1, 1, 0, 0, 1, 1, 1, 1, 0, 1}, "Engelsk", "International Business"};
    student_array[7]  = {{0, 1, 1, 1, 0, 1, 0, 1, 1, 1}, "Biologi", "Bioteknologi"};
    student_array[8]  = {{1, 1, 0, 0, 0, 0, 1, 1, 1, 1}, "Fysik", "Ingenioervidenskab"};
    student_array[9]  = {{0, 1, 1, 1, 1, 1, 0, 1, 0, 0}, "Dansk", "Kommunikation"};
    student_array[10] = {{1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, "Engelsk", "Jura"};
    student_array[11] = {{1, 0, 1, 0, 0, 1, 1, 0, 1, 0}, "Matematik", "Statistik"};
    student_array[12] = {{1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, "Virksomhedsoekonomi", "Oekonomi"};
}
