#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256

int main()
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
			break;

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
			break;

		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error creating child process");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execl(command, command, NULL) == -1)
			{
				perror("Error executing command");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;
			wait(&status);
		}
	}

	return (0);
}
