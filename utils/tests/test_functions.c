#include <stdio.h>
#include <stdbool.h>
#include <string.h>



#define RED     "\x1b[1;31m"
#define GREEN   "\x1b[1;32m"
#define RESET_COLOR   "\x1b[0m"




void describe(char *description) {

    printf("\n%s%s%s\n", GREEN, description, RESET_COLOR);

}

void finishTests(testsPassed, totalTests){
    if(testsPassed < totalTests){
        printf("\n%sPASSED %d of %d tests.%s", RED, testsPassed, totalTests, RESET_COLOR);
    }else{
        printf("\nPASSED %d of %d tests.",testsPassed, totalTests);
    }
}
int expectToBeTrue(char *description, int condition) {

    printf("%s%s: ", RESET_COLOR, description);

    if (condition) {
        printf("%sPASSED%s\n", GREEN, RESET_COLOR);
    } else {
        printf("%sNOT PASSED%s\n", RED, RESET_COLOR);
    }
    return condition;
}

int expectToBe_str(char *description, char *expected_content, char *actual_content) {
    printf("%s%s: ", RESET_COLOR, description);
    if (strcmp(expected_content, actual_content) == 0) {
        printf("%sPASSED%s\n", GREEN, RESET_COLOR);
        return 1;
    } else {
        printf("%sNOT PASSED%s\n", RED, RESET_COLOR);
        printf("%sExpected:%s\n%s\n", RESET_COLOR, expected_content, GREEN);
        printf("%sActual:%s\n%s\n", RESET_COLOR, actual_content, RED);
        return 0;
    }
}

int expectToNOTBe_str(char *description, char *expected_content, char *actual_content) {
    printf("%s%s: ", RESET_COLOR, description);
    if (strcmp(expected_content, actual_content) != 0) {
        printf("%sPASSED%s\n", GREEN, RESET_COLOR);
        return 1;
    } else {
        printf("%sNOT PASSED%s\n", RED, RESET_COLOR);
        printf("%sExpected:%s\n%s\n", RESET_COLOR, expected_content, GREEN);
        printf("%sActual:%s\n%s\n", RESET_COLOR, actual_content, RED);
        return 0;
    }
}

