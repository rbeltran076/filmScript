#include <stdlib.h>
#include <string.h>
#include "lexer.h"

Token *tokenize(const char *code)
{
    Token *head = NULL;
    Token *current = NULL;
    // Newlines and spaces
    const char *delimiters = " \n";
    char *tokenValue = strtok(strdup(code), delimiters);
    while (tokenValue != NULL)
    {
        Token *token = (Token *)malloc(sizeof(Token));
        token->type = KEYWORD;
        token->value = strdup(tokenValue);
        token->next = NULL;
        // Check for brackets
        char *parentheses = strchr(tokenValue, '(');
        if (parentheses != NULL)
        {
            *parentheses = '\0';
            token->next = (Token *)malloc(sizeof(Token));
            token->next->type = KEYWORD;
            token->next->value = strdup(parentheses + 1);
            token->next->next = NULL;
        }
        if (current == NULL)
        {
            head = token;
            current = token;
        }
        else
        {
            current->next = token;
            current = token;
        }

        tokenValue = strtok(NULL, delimiters);
    }

    return head;
}