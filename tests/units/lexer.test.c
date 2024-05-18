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
#include "test_functions.h"



int testsPassed = 0;
char* EXPECTED_LEXER_OUTPUT = "@TOKEN_SYMBOLimportTOKEN_IDENTIFIER(TOKEN_SYMBOLioTOKEN_STRING)TOKEN_SYMBOLpubTOKEN_IDENTIFIERfnTOKEN_IDENTIFIERmy_funcTOKEN_IDENTIFIER(TOKEN_SYMBOL)TOKEN_SYMBOLstringTOKEN_IDENTIFIERstoreTOKEN_IDENTIFIERnameTOKEN_IDENTIFIER=TOKEN_SYMBOLMichealTOKEN_STRINGIOTOKEN_IDENTIFIER.TOKEN_SYMBOLwriteTOKEN_IDENTIFIER(TOKEN_SYMBOL2.312TOKEN_STRING+TOKEN_OPERATOR1.746TOKEN_STRING)TOKEN_SYMBOLIOTOKEN_IDENTIFIER.TOKEN_SYMBOLwriteTOKEN_IDENTIFIER(TOKEN_SYMBOL2TOKEN_IDENTIFIER.TOKEN_SYMBOL325TOKEN_IDENTIFIER)TOKEN_SYMBOLIOTOKEN_IDENTIFIER.TOKEN_SYMBOLwriteTOKEN_IDENTIFIER(TOKEN_SYMBOLHello, World, TOKEN_STRING+TOKEN_OPERATORnameTOKEN_IDENTIFIER)TOKEN_SYMBOLendTOKEN_IDENTIFIERautomateTOKEN_IDENTIFIER(TOKEN_SYMBOL*TOKEN_STRING)TOKEN_SYMBOLendTOKEN_IDENTIFIEREOFTOKEN_EOF";
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
   describe("File testing");
   testsPassed += expectToBeTrue("The file should be runned from its original path \\tests\\units\\bin", verify_execution_directory("\\tests\\units\\bin"));
   
   describe("Reading file");
   char* file_content;

   file_content = read_file("..\\code.solg");
   testsPassed += expectToNOTBe_str("The file content should be able to be opened ", "$<ERROR.FAILED_TO_OPEN_FILE>$", file_content);
   testsPassed += expectToNOTBe_str("The file content should not be NULL", "$<ERROR.NULL_FILE_CONTENT>$", file_content);
   
   
   describe("Testing lexer function");
   Token* tokens = lexize(file_content);
   free(file_content);

   
   Token* current = tokens;
   char lexerOutput[1000] = "";

   while (current) {
      strcat(lexerOutput, current->lexeme);
      strcat(lexerOutput, token_type_to_string(current->kind));
      current = current->next;
   }

   testsPassed += expectToBe_str("Lexer output test ", EXPECTED_LEXER_OUTPUT, lexerOutput);

   while (tokens) {
      Token* temp = tokens;
      tokens = tokens->next;
      free(temp->lexeme);
      free(temp);
    }
   finishTests(testsPassed, 4);
      
   getchar(); // Prevent to close window on done.
   return 0;
}
