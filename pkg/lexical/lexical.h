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
    TokenType kind;    /**< Type of the token. */
    char* lexeme;      /**< Lexeme associated with the token. */
    struct Token* next;/**< Pointer to the next token in a linked list. */
} Token;

void lexer_init(const char* source); /**< Initializes the lexer with the source code. */
void free_tokens(Token* head); /**< Free all tokens. */
Token* add_token(Token* head, Token* new_token); /**< Retrieve a token with next token and proceed. */
Token* create_token(const int cur_index, const int start, const char* source); /**< Retrieves a created token. */
Token* lexer_next_token(const char* source, const int source_size, int* cur_index); /**< Retrieves the next token from the source code. */

#endif