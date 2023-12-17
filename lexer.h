#ifndef LEXER_H
#define LEXER_H

// Define token types
typedef enum
{
    KEYWORD,
    IDENTIFIER,
} TokenType;

// Define the structure for a token
typedef struct Token
{
    TokenType type;
    char *value;
    struct Token *next; // Pointer to the next token
} Token;

// Function to tokenize the input code
Token *tokenize(const char *code);

#endif // LEXER_H
