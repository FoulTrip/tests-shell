#include <stdio.h>
#include <stdlib.h>
#include "../include/executeCommand.h"

#define MAX_INPUT_LENGTH 256

int main()
{
	char input[MAX_INPUT_LENGTH];
	printf("SIMPLE SHELL by: Ricardo Valdez and David Vasquez\n");

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		executeCommand(input);
	}

	return (0);
}
