#include "../include/main.h"

/**
 * PrintEnvironment - Prints the system environment variables
 */
void printEnvironment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}