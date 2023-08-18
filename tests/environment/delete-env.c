#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
	int i, j;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		/* Invalid variable name */
		return (-1);
	}

	/* Iterate through the environment variables */
	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			for (j = i; environ[j] != NULL; ++j)
			{
				environ[j] = environ[j + 1];
			}
			environ[j] = NULL;
			return (0);
		}
	}

        /*  */
	return (-1);
}

int main()
{
	setenv("TEST_VARIABLE", "hello, World", 1);

	printf("Before removal: TEST_VARIABLE=%s\n", getenv("TEST_VARIABLE"));

	_unsetenv("TEST_VARIABLE");

	printf("After removal: TEST_VARIABLE=%s\n", getenv("TEST_VARIABLE"));

	return (0);
}
