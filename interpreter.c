#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "parser.h"

int evaluateCondition(Node *conditionNode)
{
    // Assuming simple conditions for demonstration
    int conditionValue = atoi(conditionNode->left->token->value);

    return conditionValue;
}

void interpret(Node *ast)
{
    if (strcmp(ast->token->value, "Inception") == 0)
    {
        printf("Starting filmScript!\n");

        // Evaluate the condition
        int condition = evaluateCondition(ast->left);
        if (condition > 0)
        {
            if (ast->left != NULL)
            {
                interpret(ast->left);
            }
        }
        else
        {
            if (ast->right != NULL)
            {
                interpret(ast->right);
            }
        }
    }
    else if (strcmp(ast->token->value, "Play") == 0)
    {
        // "Play"
        printf("Playing: %s\n", ast->right->token->value);
    }
    else if (ast->type == IDENTIFIER || ast->type == LITERAL)
    {
        printf("Condition: %s\n", ast->token->value);
    }
    else
    {
        printf("Printing: %s\n", ast->token->value);
    }
}
