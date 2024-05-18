#include <stdio.h>
#include <string.h>

#define COLOR_RED     "\x1b[1;31m"
#define COLOR_GREEN   "\x1b[1;32m"
#define COLOR_RESET   "\x1b[0m"

void describe(const char *description) {
	printf("\n%sTest Description: %s%s\n", COLOR_GREEN, description, COLOR_RESET);
}

void finalizeTests(int testsPassed, int totalTests) {
	if (testsPassed < totalTests)
		printf("\n%sTest Results: PASSED %d of %d tests.%s\n", COLOR_RED, testsPassed, totalTests, COLOR_RESET);
	else
		printf("\nTest Results: PASSED %d of %d tests.\n", testsPassed, totalTests);
}

int expectTrue(const char *description, int condition) {
	printf("%sExpectation: %s%s: ", COLOR_RESET, description, COLOR_RESET);
	if (condition)
		printf("%sPASSED%s\n", COLOR_GREEN, COLOR_RESET);
	else
		printf("%sNOT PASSED%s\n", COLOR_RED, COLOR_RESET);
	return condition;
}

int expectString(const char *description, const char *expected, const char *actual) {
	printf("%sExpectation: %s%s: ", COLOR_RESET, description, COLOR_RESET);
	if (strcmp(expected, actual) == 0) {
		printf("%sPASSED%s\n", COLOR_GREEN, COLOR_RESET);
		return 1;
	} else {
		printf("%sNOT PASSED%s\n", COLOR_RED, COLOR_RESET);
		printf("%sExpected:%s\n%s\n", COLOR_RESET, expected, COLOR_GREEN);
		printf("%sActual:%s\n%s\n", COLOR_RESET, actual, COLOR_RED);
		return 0;
	}
}

int expectNotString(const char *description, const char *unexpected, const char *actual) {
	printf("%sExpectation: %s%s: ", COLOR_RESET, description, COLOR_RESET);
	if (strcmp(unexpected, actual) != 0) {
		printf("%sPASSED%s\n", COLOR_GREEN, COLOR_RESET);
		return 1;
	} else {
		printf("%sNOT PASSED%s\n", COLOR_RED, COLOR_RESET);
		printf("%sUnexpected:%s\n%s\n", COLOR_RESET, unexpected, COLOR_RED);
		printf("%sActual:%s\n%s\n", COLOR_RESET, actual, COLOR_GREEN);
		return 0;
	}
}
