#include "CuTest.h"
#include "../include/header.h"

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
