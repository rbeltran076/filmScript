#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

char *readCodeFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *code = (char *)malloc(file_size + 1);
    if (code == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    fread(code, 1, file_size, file);
    code[file_size] = '\0';

    fclose(file);

    return code;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <CineScript file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    char *code = readCodeFromFile(filename);

    Token *tokens = tokenize(code);
    Node *ast = parse(tokens);
    interpret(ast);

    free(code); // Free allocated memory

    return 0;
}
