/**
 * @file lexer_test.c
 * @brief Test program for the lexical analyzer.
 *
 * This program demonstrates the usage of the lexical analyzer
 * by accepting a text file, initializing the lexer,
 * and tokenizing the text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "lexical.h"
#include "read_file.h"
#include "directory_check.h"

/**
 * @brief Converte um enum `TokenType` para uma string representando o tipo de token.
 * 
 * @param type O tipo de token a ser convertido.
 * @return Um ponteiro para a string representando o tipo de token.
 */
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

/**
 * @brief Main function to test the lexical analyzer.
 * 
 * This function reads the content of a text file, initializes
 * the lexical analyzer, tokenizes the text file, and prints
 * the resulting tokens to the console.
 * 
 * @return 0 on success, non-zero on failure.
 */
int main() {
   if (!verify_execution_directory("\\tests\\units\\bin")) {
      fprintf(stderr, "On running this test, run from his original path on: '\\tests\\units\\bin' to prevent errors.\n");
      getchar();
      return 1;
   }
   char* file_content;
   file_content = read_file("..\\code.solg");

   Token* tokens = lexize(file_content);
   free(file_content);

   Token* current = tokens;
   while (current) {
      printf("Token Value: %s | Token Type: %s | (Line: %d, Column: %d)\n", current->lexeme, token_type_to_string(current->kind), current->line, current->column);
      current = current->next;
   }

   printf("Done. Press any key to exit.");
   getchar(); // Prevent to close window on done.
   return 0;
}
