/**
 * @file lexical.c
 * @brief Implementation of a lexical analyzer for tokenizing source code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexical.h"

#define IS_ALPHA(c)  (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
#define IS_DIGIT(c)  ((c) >= '0' && (c) <= '9')
#define IS_ALNUM(c)  (IS_ALPHA(c) || IS_DIGIT(c))
#define IS_WSPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')

Token* lexer_next_token(const char* source, const int source_size, int cur_index) {
    /**
     * Function to retrieve the next token from the input source code.
     * 
     * @param source The input source code string.
     * @param source_size The size of the input source code string.
     * @param cur_index The current index in the source code string.
     * @return A pointer to the next token.
     */

    if (cur_index >= source_size) {
        Token* token = (Token*)malloc(sizeof(Token));
        token->kind = TOKEN_EOF;
        token->lexeme = NULL;
        token->next = NULL;
        return token;
    }

    while (IS_WSPACE(source[cur_index]))
        cur_index++;

    // Getting operators.
    if (source[cur_index] == '+' || source[cur_index] == '-' || source[cur_index] == '*' || source[cur_index] == '/') {
        Token* token = (Token*)malloc(sizeof(Token)); // Alloc memory necessary to initialize this Token structure.

        token->kind = TOKEN_OPERATOR;
        token->lexeme = (char*)malloc(2);
        token->lexeme[0] = source[cur_index];
        token->lexeme[1] = '\0';

        token->next = NULL;
        return token;
    }

    // Getting strings.
    if (source[cur_index] == '"') {
        int start = cur_index + 1;
        cur_index++;

        while(source[cur_index] != '"' && cur_index < source_size)
            cur_index++;

        if (source[cur_index] == '"') {
            Token* token = (Token*)malloc(sizeof(Token)); // Alloc memory necessary to initialize this Token structure.
            token->kind = TOKEN_STRING;

            int lexeme_length = cur_index - start + 1;
            token->lexeme = (char*)malloc(lexeme_length);
            strncpy(token->lexeme, &source[start], lexeme_length);
            token->lexeme[lexeme_length - 1] = '\0';

            token->next = NULL;
            return token;
        }
    }

    return NULL;
}


void lexer_init(const char* source) {
    const int source_size = strlen(source);
    int cur_index = 0;

    while (cur_index < source_size) {
        Token* token = lexer_next_token(source, source_size, cur_index);

        if (token != NULL)
            printf("Token Value: %s | Token Type: %d\n", token->lexeme, token->kind); // Show token value.
        cur_index++;
    }
}
