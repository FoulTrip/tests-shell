#include "prompt.h"

#define MAX_INPUT_LENGTH 1024

void print_prompt()
{
    if (isatty(STDIN_FILENO))
    {
        printf("($) ");
        fflush(stdout);
    }
}

char *read_input()
{
    char *input = NULL;
    size_t input_size = 0;

    if (getline(&input, &input_size, stdin) == -1)
    {
        perror("impossible to read the entry");
        exit(EXIT_FAILURE);
    }

    input[strcspn(input, "\n")] = '\0';

    return (input);
}