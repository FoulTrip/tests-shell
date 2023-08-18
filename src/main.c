#include "prompt.h"
#include "command.h"
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    char *input;

    while (1)
    {
        print_prompt();
        input = read_input();

        if (strcmp(input, "exit") == 0)
        {
            free(input);
            break;
        }

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Error creating a child process");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            execute_command(input);
            exit(EXIT_SUCCESS);
        }
        else
        {
            wait(NULL);
        }

        free(input);
    }

    return (0);
}