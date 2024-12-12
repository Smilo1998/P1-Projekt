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
  FILE *test_file = fopen("testeducations.txt", "r");
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




// Testing af Manhattan Distance
double manhattanDistance(const double array_user[], const double array_profile[]){
    int i; 
    double result = 0;
    // Udregner summen af forskellen mellem de to arrays
    for(i = 0; i < MAX_PROCESSED_DATA; i++){
        result += fabs((array_user[i]-array_profile[i])); // Summerer 
    }
    return result;
}

void test_manhattan1(CuTest *tc){
  double user[MAX_PROCESSED_DATA] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  double elev[MAX_PROCESSED_DATA] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  double actual = manhattanDistance(user, elev);
  double expected = 1;

  CuAssertDblEquals(tc, expected, actual, 0.001);
}

void test_manhattan2(CuTest *tc){
  double user[MAX_PROCESSED_DATA] = {3, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1};
  double elev[MAX_PROCESSED_DATA] = {0, 1, 0, 1, 1, 1, 3, 1, 1, 1, 1, 1};

  double actual = manhattanDistance(user, elev);
  double expected = 7;

  CuAssertDblEquals(tc, expected, actual, 0.001);
}

void test_manhattan3(CuTest *tc){
  double user[MAX_PROCESSED_DATA] = {3, 1, 1, 0, 2, 1, 1, 1, 0, 1, 1, 3};
  double elev[MAX_PROCESSED_DATA] = {1, 2, 0, 1, 1, 1, 3, 1, 1, 1, 2, 1};

  double actual = manhattanDistance(user, elev);
  double expected = 12;

  CuAssertDblEquals(tc, expected, actual, 0.001);
}

void test_manhattan4(CuTest *tc){
  double user[MAX_PROCESSED_DATA] = {3, 3, 1, 1, 2, 1, 1, 1, 3, 1, 3, 3};
  double elev[MAX_PROCESSED_DATA] = {0, 0, 0, 1, 1, 1, 3, 1, 1, 1, 0, 0};

  double actual = manhattanDistance(user, elev);
  double expected = 18;

  CuAssertDblEquals(tc, expected, actual, 0.001);
}

CuSuite *test_manhattan_GetSuite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_manhattan1);
  SUITE_ADD_TEST(suite, test_manhattan2);
  SUITE_ADD_TEST(suite, test_manhattan3);
  SUITE_ADD_TEST(suite, test_manhattan4);
  
  return suite;
}



