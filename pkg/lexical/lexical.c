#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexical.h"

#define IS_ALPHA(c)  (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
#define IS_DIGIT(c)  ((c) >= '0' && (c) <= '9')
#define IS_ALNUM(c)  (IS_ALPHA(c) || IS_DIGIT(c))
#define IS_WSPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')

Token* lexer_next_token(const char* source, const int source_size, const int cur_index) {
    // W.I.P
}

void lexer_init(const char* source) {
	const int source_size = strlen(source);
	printf("%s", source);
    printf("%d", source_size);
}