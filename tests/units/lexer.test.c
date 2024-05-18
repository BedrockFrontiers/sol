/**
 * @file lexer.test.c
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
#include "test_functions.h"

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
   int testsPassed = 0;
   describe("Testing file.");
   testsPassed += expectTrue("The file should be runned from it's original path \\tests\\units\\bin", verify_execution_directory("\\tests\\units\\bin"));
   
   describe("Reading file");
   char* file_content;

   file_content = read_file("..\\code.solg");
   testsPassed += expectNotString("The file content should be able to be opened ", "$<ERROR.FAILED_TO_OPEN_FILE>$", file_content);
   testsPassed += expectNotString("The file content should not be NULL", "$<ERROR.NULL_FILE_CONTENT>$", file_content);
   
   describe("Testing lexer function");
   Token* tokens = lexize(file_content);
   free(file_content);

   Token* current = tokens;
   while (current) {
      printf("Token Value: %s | Token Type: %s | (Line: %d, Column: %d)\n", current->lexeme, token_type_to_string(current->kind), current->line, current->column);
      current = current->next;
   }

   free_tokens(tokens);
   finalizeTests(testsPassed, 3);
      
   getchar(); // Prevent to close window on done.
   return 0;
}