#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "parser.h"
#include <stdbool.h>

bool evaluateCondition(Node *conditionNode)
{
    if (conditionNode == NULL) {
        // Handle the case where the node is empty or invalid
        return false;
    }

    if (conditionNode->type == LITERAL) {
        // If the node is a literal, interpret it as a boolean
        return strcmp(conditionNode->token->value, "true") == 0;
    }

    if (conditionNode->type == OPERATOR) {
        // If the node is > operator
        if (strcmp(conditionNode->token->value, ">") == 0) {
            return evaluateCondition(conditionNode->left) > evaluateCondition(conditionNode->right);
        }
        // If the node is < operator
        if (strcmp(conditionNode->token->value, "<") == 0) {
            return evaluateCondition(conditionNode->left) < evaluateCondition(conditionNode->right);
        }
        // If the node is == operator
        if (strcmp(conditionNode->token->value, "==") == 0) {
            return evaluateCondition(conditionNode->left) == evaluateCondition(conditionNode->right);
        }

        // Handle unsupported operators
        printf("Unsupported operator: %s\n", conditionNode->token->value);
        return false;
    }

    // Handle other cases (identifiers, etc.) as needed
    printf("Unsupported condition type\n");
    return false;
}

void interpret(Node *ast)
{
    printf("Starting filmScript!\n---------------\n\n");
    if (strcmp(ast->token->value, "What_if") == 0)
    {

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
