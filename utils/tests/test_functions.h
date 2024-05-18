#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H


void describe(char *description);
void finishTests(testsPassed, totalTests);
int expectToBeTrue(char *description, int condition);
int expectToBe_str(char *description, char *expected_content, char *actual_content);
int expectToNOTBe_str(char *description, char *expected_content, char *actual_content);

#endif
