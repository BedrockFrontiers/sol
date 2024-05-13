/**
 * @file lexer_test.c
 * @brief Test program for the lexical analyzer.
 *
 * This program demonstrates the usage of the lexical analyzer
 * by accepting input from the user, initializing the lexer,
 * and tokenizing the input text.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexical.h"
#include "input_reader.h"

int main() {
    char* input;

    printf("Insert your input here: ");
    input = read_input();

    Token* tokens = lexize(input);
    free(input);

    Token* current = tokens;
    while (current) {
        printf("Token Value: %s | Token Type: %d | Token Line: %d\n", current->lexeme, current->kind, current->line);
        current = current->next;
    }

    getchar(); // Prevent to close window on done.
    return 0;
}
