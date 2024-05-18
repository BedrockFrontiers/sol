/**
 * @file lexical.c
 * @brief Implementation of a lexical analyzer for tokenizing source code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexical.h"

#define OPERATORS "+-*/^"

int is_operator(char c) {
	return strchr(OPERATORS, c) != NULL;
}

const char* token_type_to_string(TokenType type) {
   switch (type) {
      case TOKEN_NUMBER:
         return "TOKEN_NUMBER";
      case TOKEN_IDENTIFIER:
         return "TOKEN_IDENTIFIER";
      case TOKEN_SYMBOL:
         return "TOKEN_SYMBOL";
      case TOKEN_OPERATOR:
         return "TOKEN_OPERATOR";
      case TOKEN_BOOLEAN:
         return "TOKEN_BOOLEAN";
      case TOKEN_STRING:
         return "TOKEN_STRING";
      case TOKEN_EOF:
         return "TOKEN_EOF";
   }
}

Token* create_token(const int cur_index, const int start, const int cur_line, const int cur_column, const char* source, TokenType kind) {
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
	token->column = cur_column;
	token->kind = kind;

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

Token* lexize(const char* source) {
	const int source_size = strlen(source);
	int cur_index = 0;
	int cur_line = 1;
	int cur_column = 1;
	int column_offset = 0;
	Token* token_list = NULL;

	while (cur_index < source_size) {
		while (cur_index < source_size && isspace(source[cur_index])) {
			if (source[cur_index] == '\n') {
				cur_line++;
				column_offset = cur_index + 1;
			}
			cur_index++;
		}

		if (cur_index >= source_size) break;

		if (source[cur_index] == '/' && cur_index + 1 < source_size) {
			if (source[cur_index + 1] == '/') {
				while (cur_index < source_size && source[cur_index] != '\n')
					cur_index++;
				continue;
			} else if (source[cur_index + 1] == '*') {
				cur_index += 2;
				while (cur_index < source_size - 1) {
					if (source[cur_index] == '*' && source[cur_index + 1] == '/') {
						cur_index += 2;
						break;
					}
					if (source[cur_index] == '\n') {
						cur_line++;
						column_offset = cur_index + 1;
					}
					cur_index++;
				}
				continue;
			}
		}

		cur_column = cur_index - column_offset + 1;

		if (source[cur_index] == '"') {
			int start = cur_index + 1;
			cur_index++;
			while (cur_index < source_size && source[cur_index] != '"') {
				if (source[cur_index] == '\\')
					cur_index++;
				cur_index++;
			}

			if (cur_index >= source_size) {
				printf("Error: Unterminated string starting at line: %d on column: %d\n", cur_line, cur_index);
				exit(EXIT_FAILURE);
			}
			Token* token = create_token(cur_index, start, cur_line, cur_column, source, TOKEN_STRING);
			token_list = add_token(token_list, token);
			cur_index++;
			continue;
		}

		if (isdigit(source[cur_index])) {
			int start = cur_index;

			while (cur_index < source_size && isdigit(source[cur_index]))
				cur_index++;

			if (cur_index < source_size && source[cur_index] == '.') {
				cur_index++;
				while (cur_index < source_size && isdigit(source[cur_index]))
					cur_index++;
			}

			Token* token = create_token(cur_index, start, cur_line, cur_column, source, TOKEN_NUMBER);
			token_list = add_token(token_list, token);
			continue;
		}

		if (isalpha(source[cur_index]) || source[cur_index] == '_') {
			int start = cur_index;
			while (cur_index < source_size && (isalnum(source[cur_index]) || source[cur_index] == '_'))
				cur_index++;

			Token* token = create_token(cur_index, start, cur_line, cur_column, source, TOKEN_IDENTIFIER);
			if (strcmp(token->lexeme, "true") == 0 || strcmp(token->lexeme, "false") == 0)
				token->kind = TOKEN_BOOLEAN;
			token_list = add_token(token_list, token);
			continue;
		}

		if (is_operator(source[cur_index])) {
			Token* token = create_token(cur_index + 1, cur_index, cur_line, cur_column, source, TOKEN_OPERATOR);
			token_list = add_token(token_list, token);
			cur_index++;
			continue;
		} else {
			Token* token = create_token(cur_index + 1, cur_index, cur_line, cur_column, source, TOKEN_SYMBOL);
			token_list = add_token(token_list, token);
			cur_index++;
			continue;
		}

		continue;
	}

	Token* eof_token = create_token(cur_index, cur_index, cur_line, -1, source, TOKEN_EOF);
	eof_token->lexeme = strdup("EOF");
	token_list = add_token(token_list, eof_token);

	return token_list;
}