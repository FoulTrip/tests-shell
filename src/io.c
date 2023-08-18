#include "io.h"

void redirect_output(const char *filename)
{

    int fd = open(filename, 0_WRONLY | 0_CREAT | 0_TRUNC, 0666);

    if (fd < 0)
    {
        perror("Error redirecting the output");
        exit(EXIT_FAILURE);
    }

    if (dup2(fd, STDOUT_FILENO) < 0)
    {
        perror("Error redirecting the output");
        exit(EXIT_FAILURE);
    }

    close(fd);
}