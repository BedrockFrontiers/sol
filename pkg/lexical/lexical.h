/**
 * @file lexical.h
 * @brief Defines tokens and functions for lexical analysis.
 */

#ifndef LEXICAL_H
#define LEXICAL_H

typedef enum {
    TOKEN_NUMBER,      /**< Token represents a numeric value. */
    TOKEN_IDENTIFIER,  /**< Token represents an identifier. */
    TOKEN_SYMBOL,      /**< Token represents a symbol. */
    TOKEN_OPERATOR,    /**< Token represents an operator. */
    TOKEN_BOOLEAN,     /**< Token represents a boolean value. */
    TOKEN_STRING,      /**< Token represents a string. */
    TOKEN_EOF          /**< Token represents end of file. */
} TokenType;

typedef struct Token {
    TokenType kind;     /**< Type of the token. */
    char* lexeme;       /**< Lexeme associated with the token. */
    int line;           /**< Line of token. */
    struct Token* next; /**< Pointer to the next token in a linked list. */
} Token;

void free_token(Token* token); /**< Free token. */
void free_tokens(Token* head); /**< Free all tokens. */
Token* lexize(const char* source); /**< Retrieve a token list from the lexer with the source code. */
Token* add_token(Token* head, Token* new_token); /**< Retrieve a token with next token and proceed. */
Token* create_token(const int cur_index, const int start, const int line, const char* source); /**< Retrieves a created token. */
Token* lexer_next_token(const char* source, const int source_size, int* cur_index, int* cur_line); /**< Retrieves the next token from the source code. */

#endif