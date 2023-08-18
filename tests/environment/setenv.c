#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
		return (-1);

	int len_name = strlen(name);
	int len_value = strlen(value);
	int i;

	for (i = 0, environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], len_name) == 0 && environ[i][len_name] == '=')
		{
			if (overwrite == 0)
				return (0);
			else
			{
				char *new_entry = (char *)malloc(len_name + len_value + 2);
				sprintf(new_entry, "%s=%s", name, value);
				environ[i] = new_entry;
				return (0);
			}
		}
	}

	/* Variable doesn't exist, error */
	int new_entry_len = len_name + len_value + 2;
	char *new_entry = (char *)malloc(new_entry_len);
	sprintf(new_entry, "%s=%s", name, value);

	int env_size = 0, i;
	while (environ[env_size] != NULL)
	{
		env_size++;
	}

	char **new_environ = (char **)malloc((env_size + 2) * sizeof(char *));
	for (i = 0; i < env_size; i++)
		new_environ[i] = environ[i];

	new_environ[new_size] = new_entry;
	new_environ[env_size + 1] = NULL;

	environ = new_environ;

	return (0);
}


