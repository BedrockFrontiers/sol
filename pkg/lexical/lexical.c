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

/**
 * Function to create a new token.
 * 
 * This function creates a new token based on the given parameters.
 * 
 * @param cur_index The current index in the source code string.
 * @param start The starting index of the lexeme in the source code string.
 * @param source The input source code string.
 * @return A pointer to the newly created token.
 */
Token* create_token(const int cur_index, const int start, const int cur_line, const char* source) {
    Token* token = (Token*)malloc(sizeof(Token));

    int lexeme_length = cur_index - start + 1;
    token->lexeme = (char*)malloc(lexeme_length);
    strncpy(token->lexeme, &source[start], lexeme_length);
    token->lexeme[lexeme_length - 1] = '\0';
    token->line = cur_line;

    token->next = NULL;
    return token;
}

/**
 * Function to add a new token to the end of the token list.
 * 
 * This function adds a new token to the end of the existing token list. If the
 * list is empty, it returns the new token as the head of the list.
 * 
 * @param head The head of the current token list.
 * @param new_token The new token to be added.
 * @return The head of the updated token list.
 */
Token* add_token(Token* head, Token* new_token) {
    if (head == NULL) {
        return new_token;
    } else {
        Token* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_token;
        return head;
    }
}

/**
 * Function to free the memory allocated for a token.
 * 
 * This function frees the memory allocated for the given token's lexeme
 * and the token itself.
 * 
 * @param token The token to be freed.
 */
void free_token(Token* token) {
    free(token->lexeme);
    free(token);
}

/**
 * Function to free the memory allocated for the token list.
 * 
 * This function iterates through the token list and frees the memory allocated
 * for each token and its lexeme. It also frees the memory allocated for the token
 * list itself.
 * 
 * @param head The head of the token list to be freed.
 */
void free_tokens(Token* head) {
    while (head != NULL) {
        Token* temp = head;
        head = head->next;
        free_token(temp);
    }
}

/**
 * Function to retrieve the next token from the input source code.
 * 
 * @param source The input source code string.
 * @param source_size The size of the input source code string.
 * @param cur_index The current index in the source code string.
 * @return A pointer to the next token.
 */
Token* lexer_next_token(const char* source, const int source_size, int* cur_index, int* cur_line) {
    while (*cur_index < source_size && IS_WSPACE(source[*cur_index])) {
        (*cur_index)++;
    }

    if (source[*cur_index] == '\n') {
        (*cur_index)++;
        (*cur_line)++;
    }

    if (*cur_index >= source_size) {
        Token* token = create_token(*cur_index, *cur_index, *cur_line, source);
        token->kind = TOKEN_EOF;
        return token;
    }

    if (source[*cur_index] == '"') {
        int start = (*cur_index) + 1;
        (*cur_index)++;

        while (*cur_index < source_size && source[*cur_index] != '"') {
            if (source[*cur_index] == '\\' && *cur_index + 1 < source_size) {
                (*cur_index)++;
            }
            (*cur_index)++;
        }

        if (*cur_index < source_size && source[*cur_index] == '"') {
            Token* token = create_token(*cur_index, start, *cur_line, source);
            token->kind = TOKEN_STRING;
            (*cur_index)++;
            return token;
        }
    }

    if (IS_DIGIT(source[*cur_index])) {
        int start = *cur_index;

        while (*cur_index < source_size && IS_DIGIT(source[*cur_index])) {
            (*cur_index)++;
        }

        if (*cur_index < source_size && source[*cur_index] == '.') {
            (*cur_index)++;
            while (*cur_index < source_size && IS_DIGIT(source[*cur_index])) {
                (*cur_index)++;
            }
        }

        Token* token = create_token(*cur_index, start, *cur_line, source);
        token->kind = TOKEN_NUMBER;
        return token;
    }

    if (IS_ALPHA(source[*cur_index])) {
        int start = *cur_index;
        (*cur_index)++;

        while (*cur_index < source_size && IS_ALPHA(source[*cur_index])) {
            (*cur_index)++;
        }

        Token* token = create_token(*cur_index, start, *cur_line, source);
        if (strcmp(token->lexeme, "true") == 0 || strcmp(token->lexeme, "false") == 0) {
            token->kind = TOKEN_BOOLEAN;
        } else {
            token->kind = TOKEN_IDENTIFIER;
        }
        return token;
    }

    if (source[*cur_index] == '+' || source[*cur_index] == '-' || source[*cur_index] == '*' || source[*cur_index] == '/') {
        Token* token = create_token(*cur_index + 1, *cur_index, *cur_line, source);
        token->kind = TOKEN_SYMBOL;
        (*cur_index)++;
        return token;
    }

    Token* token = create_token(*cur_index + 1, *cur_index, *cur_line, source);
    token->kind = TOKEN_SYMBOL;
    (*cur_index)++;
    return token;
}

/**
 * Function to initialize the lexical analyzer and tokenize the input source code.
 * 
 * This function iterates through the input source code string and identifies tokens
 * such as operators and strings. It prints the value and type of each token found.
 * 
 * @param source The input source code string.
 */
Token* lexize(const char* source) {
    const int source_size = strlen(source);
    Token* token_list = NULL;
    int cur_index = 0;
    int cur_line = 1;

    while (cur_index < source_size) {
        Token* token = lexer_next_token(source, source_size, &cur_index, &cur_line);
        
        if(token->kind == TOKEN_EOF)
            break;

        if (token) {
            token_list = add_token(token_list, token);
        }
    }

    Token* current = token_list;
    while (current) {
        printf("Token Value: %s | Token Type: %d | Token Line: %d\n", current->lexeme, current->kind, current->line);
        current = current->next;
    }

    return token_list;
}
