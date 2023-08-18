#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
	int i, j;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)

	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			for (j = i; environ[j] != NULL; ++j)
			{
				environ[j] = environ[j + i];
			}
			return (0);
		}
	}

	return (-1);
}

int main()
{
	setenv("TEST_VARIABLE", "hello, World", 1);

	printf("Before removal: TEST_VAR=%s\n", getenv("#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
	int i, j;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)

	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			for (j = i; environ[j] != NULL; ++j)
			{
				environ[j] = environ[j + i];
			}
			return (0);
		}
	}

	return (-1);
}

int main()
{
	setenv("TEST_VARIABLE", "hello, World", 1);

	printf("Before removal: TEST_VARIABLER=%s\n", getenv("TEST_VARIABLE"));

	_unsetenv("TEST_VARIABLE_CPY");

	printf("After removal: TEST_VARIABLE_CPY=%s\n", getenv("TEST_VARIABLE_CPY"));

	return (0);
}
