#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Define AST node types
typedef enum
{
    CONDITIONAL,
    PRINT_STATEMENT,
    LITERAL,
    EXPRESSION, 
    OPERATOR
} NodeType;

// Define the structure for an AST node
typedef struct Node
{
    NodeType type;
    Token *token;
    struct Node *left;
    struct Node *right;
} Node;

// Function to parse the tokenized input into an AST
Node *parse(Token *tokens);

// Function to parse condition expression
Node *parseCondition(Token *tokens);

// Function to parse general expressions
Node *parseExpression(Token *tokens);

Node *parseExpression(Token *tokens);
#endif // PARSER_H