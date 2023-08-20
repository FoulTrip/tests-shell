#include <stdio.h>
#include <stdlib.h>
#include "../include/executeCommand.h"

#define MAX_INPUT_LENGTH 256

int main()
{
	char input[MAX_INPUT_LENGTH];
	printf("SIMPLE SHELL by: FoulTrip\n");

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else if (strcspn(input, "env") == 0)
		{
			printEnvironment();
		}
		else
		{
			executeCommand(input);
		}
	}

	return (0);
}
