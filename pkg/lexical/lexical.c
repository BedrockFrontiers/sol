/**
 * @file lexical.c
 * @brief Implementation of a lexical analyzer for tokenizing source code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include "lexical.h"

#define IS_ALPHA(c)  (iswalpha(c) || (c) ==  '_')
#define IS_DIGIT(c)  ((c) >= '0' && (c) <= '9')
#define IS_ALNUM(c)  (IS_ALPHA(c) || IS_DIGIT(c))
#define IS_WSPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')

#define OPERATORS "+-*/^"

int inside_string = 0;

int is_operator(char c) {
	for (int i = 0; OPERATORS[i] != '\0'; i++) {
		if (OPERATORS[i] == c)
			return 1;
	}
	return 0;
}

Token* create_token(const int cur_index, const int start, const int cur_line, const char* source) {
	Token* token = (Token*)malloc(sizeof(Token));
	if (token == NULL) {
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	int lexeme_length = cur_index - start + 1;
	token->lexeme = (char*)malloc(lexeme_length);
	if (token->lexeme == NULL) {
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	strncpy(token->lexeme, &source[start], lexeme_length);
	token->lexeme[lexeme_length - 1] = '\0';
	token->line = cur_line;

	token->next = NULL;
	return token;
}

Token* add_token(Token* head, Token* new_token) {
	if (head == NULL) {
		return new_token;
	} else {
		Token* current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_token;
		return head;
	}
}

void free_token(Token* token) {
	free(token->lexeme);
	free(token);
}

void free_tokens(Token* head) {
	while (head != NULL) {
		Token* temp = head;
		head = head->next;
		free_token(temp);
	}
}

Token* lexer_next_token(const char* source, const int source_size, int* cur_index, int* cur_line) {
	while (*cur_index < source_size && IS_WSPACE(source[*cur_index])) {
		if (source[*cur_index] == '\n')
			(*cur_line)++;
		(*cur_index)++;
	}

	if (*cur_index >= source_size)
		return NULL;

	if (source[*cur_index] == '/' && *cur_index + 1 < source_size && source[*cur_index + 1] == '/') {
		while (*cur_index < source_size && source[*cur_index] != '\n') {
			(*cur_index)++;
		}

		(*cur_line)++;
		return lexer_next_token(source, source_size, cur_index, cur_line);
	}

	if (source[*cur_index] == '/' && *cur_index + 1 < source_size && source[*cur_index + 1] == '*') {
		(*cur_index) += 2;
		while (*cur_index < source_size - 1 && !(source[*cur_index] == '*' && source[*cur_index + 1] == '/')) {
			if (source[*cur_index] == '\n') {
				(*cur_line)++;
			}
			(*cur_index)++;
		}
		if (*cur_index < source_size - 1) {
			(*cur_index) += 2;
			return lexer_next_token(source, source_size, cur_index, cur_line);
		} else {
			printf("Error: Unterminated block comment at line %d\n", *cur_line);
			getchar();
			exit(EXIT_FAILURE);
		}
	}

	if (source[*cur_index] == '"') {
		inside_string = 1;

		int start = (*cur_index) + 1;
		(*cur_index)++;

		while (*cur_index < source_size && source[*cur_index] != '"') {
			if (source[*cur_index] == '\\' && *cur_index + 1 < source_size) {
				(*cur_index)++;
			}
			(*cur_index)++;
		}

		if (*cur_index >= source_size) {
		   printf("Error: Unterminated string starting at line %d\n", *cur_line);
		   getchar();
		   exit(EXIT_FAILURE);
		}

		if (*cur_index < source_size && source[*cur_index] == '"') {
			Token* token = create_token(*cur_index, start, *cur_line, source);
			token->kind = TOKEN_STRING;
			inside_string = 0;
			(*cur_index)++;
			return token;
		}
	}

	if (IS_ALNUM(source[*cur_index])) {
		int start = *cur_index;
		(*cur_index)++;

		while (*cur_index < source_size && IS_ALNUM(source[*cur_index]))
			(*cur_index)++;

		Token* token = create_token(*cur_index, start, *cur_line, source);
		if (strcmp(token->lexeme, "true") == 0 || strcmp(token->lexeme, "false") == 0)
			token->kind = TOKEN_BOOLEAN;
		else
			token->kind = TOKEN_IDENTIFIER;
		return token;
	}

	if (IS_DIGIT(source[*cur_index])) {
		int start = *cur_index;

		while (*cur_index < source_size && IS_DIGIT(source[*cur_index]))
			(*cur_index)++;

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

	if (is_operator(source[*cur_index])) {
		Token* token = create_token(*cur_index + 1, *cur_index, *cur_line, source);
		token->kind = TOKEN_OPERATOR;
		(*cur_index)++;
		return token;
	} else {
		Token* token = create_token(*cur_index + 1, *cur_index, *cur_line, source);
		token->kind = TOKEN_SYMBOL;
		(*cur_index)++;
		return token;
	}

	return NULL;
}

Token* lexize(const char* source) {
	const int source_size = strlen(source);
	int cur_index = 0;
	int cur_line = 1;

	Token* token_list = NULL;

	while (cur_index < source_size) {
		Token* token = lexer_next_token(source, source_size, &cur_index, &cur_line);

		if (token)
			token_list = add_token(token_list, token);
	}

	Token* eof_token = create_token(cur_index, cur_index, cur_line, source);
	eof_token->lexeme = strdup("EOF");
	eof_token->kind = TOKEN_EOF;
	token_list = add_token(token_list, eof_token);

	return token_list;
}
