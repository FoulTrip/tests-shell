#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	const char *command = "ls";
	const char *args[] = {"ls", "-l", "/tmp", NULL};
	int i;

	for (i = 0; i < 5; i++)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error when creating a child process");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execvp(command, (char *const *)args);
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
			wait(&status);
			printf("Child process %d terminated\n", i + 1);
		}
	}

	return (0);
}
