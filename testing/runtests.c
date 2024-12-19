#include "../include/header.h"
#include "CuTest.h"

// For at teste skal c filerne kompileres. Dette goeres med kommandoen: gcc cutest.c testManhattan.c testScan.c runtests.c

void RunAllTests(void);

int main(void){
    RunAllTests();
    return 0;
}

void RunAllTests(void){
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    // Adding test suites
    CuSuiteAddSuite(suite, (CuSuite *)test_manhattan_GetSuite());
    CuSuiteAddSuite(suite, (CuSuite*)test_getEducations_GetSuite());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}