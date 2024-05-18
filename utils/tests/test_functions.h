#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

/**
 * @brief Displays a description of a test.
 * 
 * @param description The description of the test.
 */
void describe(char *description);

/**
 * @brief Finalizes the tests and prints the results.
 * 
 * @param testsPassed Number of tests passed.
 * @param totalTests Total number of tests.
 */
void finalizeTests(int testsPassed, int totalTests);

/**
 * @brief Checks if a condition is true and prints the result.
 * 
 * @param description The description of the expectation.
 * @param condition The condition to be evaluated.
 * @return 1 if the condition is true, 0 otherwise.
 */
int expectTrue(char *description, int condition);

/**
 * @brief Checks if two strings are equal and prints the result.
 * 
 * @param description The description of the expectation.
 * @param expected_content The expected string content.
 * @param actual_content The actual string content.
 * @return 1 if the strings are equal, 0 otherwise.
 */
int expectString(char *description, char *expected_content, char *actual_content);

/**
 * @brief Checks if two strings are not equal and prints the result.
 * 
 * @param description The description of the expectation.
 * @param expected_content The expected string content.
 * @param actual_content The actual string content.
 * @return 1 if the strings are not equal, 0 otherwise.
 */
int expectNotString(char *description, char *expected_content, char *actual_content);

#endif