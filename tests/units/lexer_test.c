/**
 * @file lexer_test.c
 * @brief Test program for the lexical analyzer.
 *
 * This program demonstrates the usage of the lexical analyzer
 * by accepting input from the user, initializing the lexer,
 * and tokenizing the input text.
 *
 * It prompts the user to enter text, then initializes the lexer
 * with the input text and prints the tokens recognized by the lexer.
 * Finally, it exits with status 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../pkg/lexical/lexical.h"
#include "../../pkg/utils/bstring.h"

int main() {
    char* input;

    printf("Insert your input here: ");
    input = read_input();

    lexer_init(input);
    free(input);

    return 0;
}
