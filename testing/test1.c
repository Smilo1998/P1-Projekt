#include "CuTest.h"
#include "../include/header.h"

void getEducations(educations education_choice[]){
    int i;
    int j;

    FILE *education_file = fopen("testeducations.txt", "r");
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

void test_getEducationsOpen(CuTest *tc){
  FILE *test_file = fopen("../datafiles/education.txt", "r");
  CuAssertPtrNotNull(tc, test_file);
  fclose(test_file);
}

void test_getEducations1(CuTest *tc){

  educations education_array[MAX_EDUCATIONS];

  getEducations(education_array);


  //Test uddannelse 1
  CuAssertStrEquals(tc, "Software", education_array[0].name);
  CuAssertDblEquals(tc, 5.4, education_array[0].min_grade[0], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[1], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[2], 0.001);
  CuAssertDblEquals(tc, 2, education_array[0].min_grade[3], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[4], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[5], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[6], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[7], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[8], 0.001);
  CuAssertDblEquals(tc, 0, education_array[0].min_grade[9], 0.001);
  CuAssertStrEquals(tc, "https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/tekniskvidenskabeligebacheloruddannelser/civilingenioeruddannelser/software", education_array[0].link);
  

  //Test uddannelse 2
  CuAssertStrEquals(tc, "Erhvervsoekonomi", education_array[1].name);
  CuAssertDblEquals(tc, 7.9, education_array[1].min_grade[0], 0.001);
  CuAssertDblEquals(tc, 7.9, education_array[1].min_grade[1], 0.001);
  CuAssertDblEquals(tc, 6.7, education_array[1].min_grade[2], 0.001);
  CuAssertDblEquals(tc, 2, education_array[1].min_grade[3], 0.001);
  CuAssertDblEquals(tc, 2, education_array[1].min_grade[4], 0.001);
  CuAssertDblEquals(tc, 0, education_array[1].min_grade[5], 0.001);
  CuAssertDblEquals(tc, 0, education_array[1].min_grade[6], 0.001);
  CuAssertDblEquals(tc, 2, education_array[1].min_grade[7], 0.001);
  CuAssertDblEquals(tc, 0, education_array[1].min_grade[8], 0.001);
  CuAssertDblEquals(tc, 6, education_array[1].min_grade[9], 0.001);
  CuAssertStrEquals(tc, "https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/samfundsvidenskabeligebacheloruddannelser/erhvervsoekonomi/erhvervsoekonomi-ha", education_array[1].link);


  //Test uddannelse 3
  CuAssertStrEquals(tc, "Statskundskab", education_array[2].name);
  CuAssertDblEquals(tc, 10.5, education_array[2].min_grade[0], 0.001);
  CuAssertDblEquals(tc, 8.9, education_array[2].min_grade[1], 0.001);
  CuAssertDblEquals(tc, 9.0, education_array[2].min_grade[2], 0.001);
  CuAssertDblEquals(tc, 0, education_array[2].min_grade[3], 0.001);
  CuAssertDblEquals(tc, 0, education_array[2].min_grade[4], 0.001);
  CuAssertDblEquals(tc, 0, education_array[2].min_grade[5], 0.001);
  CuAssertDblEquals(tc, 0, education_array[2].min_grade[6], 0.001);
  CuAssertDblEquals(tc, 0, education_array[2].min_grade[7], 0.001);
  CuAssertDblEquals(tc, 0, education_array[2].min_grade[8], 0.001);
  CuAssertDblEquals(tc, 0, education_array[2].min_grade[9], 0.001);
  CuAssertStrEquals(tc, "https://www.ug.dk/uddannelser/bachelorogkandidatuddannelser/bacheloruddannelser/samfundsvidenskabeligebacheloruddannelser/forvaltningmv/statskundskab", education_array[2].link);

}

CuSuite *test_getEducations_GetSuite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_getEducationsOpen);
  SUITE_ADD_TEST(suite, test_getEducations1);
  

  return suite;
}




