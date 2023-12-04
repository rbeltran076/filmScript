// parser.c

#include <stdlib.h>
#include <string.h>
#include "parser.h"

Node *parse(Token *tokens)
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;

    // Check for "Inception"
    if (strcmp(tokens->value, "What If") == 0)
    {
        root->type = CONDITIONAL;
        root->token = tokens;
        tokens = tokens->next;
        // Parse the true branch
        root->left = (Node *)malloc(sizeof(Node));
        root->left->type = PRINT_STATEMENT;
        root->left->token = tokens;
        tokens = tokens->next;
        // Parse the false branch
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
