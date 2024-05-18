/**
 * @file lexical.h
 * @brief Defines tokens and functions for lexical analysis.
 */

#ifndef LEXICAL_H
#define LEXICAL_H

/**
 * @brief Represents the types of tokens used in lexical analysis.
 */
typedef enum {
    TOKEN_NUMBER,                           /**< Token represents a numeric value. */
    TOKEN_IDENTIFIER,                       /**< Token represents an identifier. */
    TOKEN_SYMBOL,                           /**< Token represents a symbol. */
    TOKEN_OPERATOR,                         /**< Token represents an operator. */
    TOKEN_BOOLEAN,                          /**< Token represents a boolean value. */
    TOKEN_STRING,                           /**< Token represents a string. */
    TOKEN_EOF                               /**< Token represents end of file. */
} TokenType;

/**
 * @brief Represents a token in the lexical analysis.
 */
typedef struct Token {
    TokenType kind;                         /**< Type of the token. */
    char* lexeme;                           /**< Lexeme associated with the token. */
    int line;                               /**< Line of token. */
    int column;                             /**< Column of token. */
    struct Token* next;                     /**< Pointer to the next token in a linked list. */
} Token;


/**
 * @brief Check if the character is a operator.
 * 
 * @param c The current character.
 */
int is_operator(char c);

/**
 * @brief Converte um enum `TokenType` para uma string representando o tipo de token.
 * 
 * @param type O tipo de token a ser convertido.
 * @return Um ponteiro para a string representando o tipo de token.
 */
const char* token_type_to_string(TokenType type);

/**
 * @brief Frees memory allocated for a single token.
 * 
 * @param token The token to be freed.
 */
void free_token(Token* token);

/**
 * @brief Frees memory allocated for a linked list of tokens.
 * 
 * @param head The head of the token linked list.
 */
void free_tokens(Token* head);

/**
 * @brief Lexical analysis of the source code to generate a token list.
 * 
 * @param source The source code to be analyzed.
 * @return A pointer to the head of the token list.
 */
Token* lexize(const char* source);

/**
 * @brief Adds a new token to the end of the token linked list.
 * 
 * @param head The head of the token linked list.
 * @param new_token The new token to be added.
 * @return A pointer to the head of the updated token list.
 */
Token* add_token(Token* head, Token* new_token);

/**
 * @brief Creates a token from the current index in the source code.
 * 
 * @param cur_index The current index in the source code.
 * @param start The starting index of the token.
 * @param cur_line The line number of the token.
 * @param cur_column The column number of the token.
 * @param source The source code string.
 * @param kind The token type of the token.
 * @return A pointer to the created token.
 */
Token* create_token(const int cur_index, const int start, const int cur_line, const int cur_column, const char* source, TokenType kind);

#endif
