#include "../include/header.h"
#include "CuTest.h"


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
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}