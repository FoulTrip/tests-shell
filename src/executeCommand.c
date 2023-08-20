#include "../include/executeCommand.h"

void executeCommand(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error when creating a child process");
		exit(EXIT_FAILURE);
	} 
	else if (child_pid == 0)
	{
		execlp(command, command, (char * )NULL);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		wait(&status);
	}

}
