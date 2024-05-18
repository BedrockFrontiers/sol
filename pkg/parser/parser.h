#ifndef PARSER_H
#define PARSER_H

/**
 * @file parser.h
 * @brief Declaration of functions and structures for parsing tokens.
 */

#include "lexical.h"

/**
 * @brief Enum representing the types of expressions in the language.
 */
typedef enum {
   EXPRESSION_BINARY_OP, /**< Binary operation */
   EXPRESSION_UNARY_OP, /**< Unary operation */
   EXPRESSION_LITERAL, /**< Literal value */
   EXPRESSION_IDENTIFIER /**< Identifier */
} ExpressionType;

/**
 * @brief Structure representing an expression node.
 */
typedef struct ExpressionNode {
   ExpressionType type; /**< Type of the expression */
   char* lexeme; /**< Lexeme of the expression */
   struct ExpressionNode* left; /**< Left child of the expression */
   struct ExpressionNode* right; /**< Right child of the expression */
} ExpressionNode;

/**
 * @brief Parses the tokens produced by the lexer into an abstract syntax tree (AST).
 * 
 * @param tokens The list of tokens produced by the lexer.
 * @return The root of the AST.
 */
ExpressionNode* parse_tokens(Token* tokens);

#endif
