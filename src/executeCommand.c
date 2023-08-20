#include "../include/executeCommand.h"

#define MAX_INPUT_LENGTH 256

void executeCommand(const char *command)
{
	const char *delimiter = " ";
	char *copyCommand = strtok(strdup(command), delimiter);
	pid_t child_pid;
	int argIndex = 1;
	char *args[MAX_INPUT_LENGTH / 2];
	args[0] = copyCommand;

	if (copyCommand == NULL)
	{
		return;
	}

	while (argIndex < MAX_INPUT_LENGTH / 2)
	{
		args[argIndex] = strtok(NULL, delimiter);
		if (args[argIndex] == NULL)
		{
			break;
		}
		argIndex++;
	}

	args[argIndex] = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error when creating a child process");
		exit(EXIT_FAILURE);
	} 
	else if (child_pid == 0)
	{
		execvp(copyCommand, args);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		wait(&status);
	}

}

void printEnvironment()
{
    extern char **environ;
    char **env = environ;

    while (*env != NULL) 
    {
        printf("%s\n", *env);
        env++;
    }
}
