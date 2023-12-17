// parser.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

Node *parse(Token *tokens)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;

    // Checking for conditionals
    if (strcmp(tokens->value, "What_if") == 0)
    {
        root->type = CONDITIONAL;
        root->token = tokens;
        tokens = tokens->next;

        // Parse the true branch
        root->left = (Node *)malloc(sizeof(Node));
        root->left->type = PRINT_STATEMENT;
        root->left->token = tokens;
        tokens = tokens->next;

        // False branch
        if (tokens != NULL && strcmp(tokens->value, "Elseworlds") == 0)
        {
            root->right = (Node *)malloc(sizeof(Node));
            root->right->type = PRINT_STATEMENT;
            root->right->token = tokens;
        }
    }
    else
    {
        // Default to PRINT_STATEMENT for simplicity
        root->type = PRINT_STATEMENT;
        root->token = tokens;
    }

    return root;
}