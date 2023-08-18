#include "pipe.h"

void execute_with_pipe(const char *command1, const char *command2)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        perror("Error creating pipeline");
        exit(EXIT_FAILURE)
    }

    pid_t pid1 = fork();

    if (pid1 < 0)
    {
        perror("Error creating child process 1");
        exit(EXIT_FAILURE);
    }
    else if (pid1 == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execute_command(command1);
        exit(EXIT_SUCCESS);
    }

    pid_t pid2 = fork();

    if (pid2 < 0)
    {
        perror("Error creating child process 2");
        exit(EXIT_FAILURE);
    }
    else if (pid2 == 0)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDOUT_FILENO);
        close(pipefd[0]);
        execute_command(command2);
        exit(EXIT_SUCCESS)
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

}