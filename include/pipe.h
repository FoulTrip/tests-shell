#ifndef PIPE_H
#define PIPE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"

void execute_with_pipe(const char *command1, const char *command2);

#endif