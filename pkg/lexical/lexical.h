#ifndef LEXICAL_H
#define LEXICAL_H

typedef enum {
	TOKEN_NUMBER,
	TOKEN_IDENTIFIER,
	TOKEN_SYMBOL,
	TOKEN_OPERATOR,
	TOKEN_BOOLEAN,
	TOKEN_STRING,
	TOKEN_EOF
} TokenType;

typedef struct Token {
	TokenType kind;
	char* lexeme;
	struct Token* next;
} Token;

void lexer_init(const char* source);
Token* lexer_next_token(const char* source, const int source_size, const int cur_index);

#endif