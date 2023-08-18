#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	int len_name, len_value, i;
	int new_entry_len, env_size;
	char *new_entry;
	char **new_environ;

	if (name == NULL || value == NULL)
		return (-1);

	len_name = strlen(name);
	len_value = strlen(value);

	new_entry_len = len_name + len_value + 2;
	new_entry = (char *)malloc(new_entry_len);
	if (new_entry == NULL)
		return (-1);

	snprintf(new_entry, new_entry_len, "%s=%s", name, value);

	env_size = 0;
	while (environ[env_size] != NULL)
		env_size++;

	new_environ = (char **)malloc((env_size + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		free(new_entry);
		return (-1);
	}

	for (i = 0; i < env_size; i++)
		new_environ[i] = environ[i];

	new_environ[env_size] =	new_entry;
	new_environ[env_size + 1] = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], len_name) == 0 && environ[i][len_name] == '=')
		{
			if (overwrite == 0)
			{
				free(new_entry);
				free(new_environ);
				return (0);
			}
			else
			{
				free(environ[i]);
				new_environ[i] = new_entry;
				environ = new_environ;
				return (0);
			}
		}
	}

	free(environ);
	environ = new_environ;

	return (0);
}

int main()
{
	int result = _setenv("MY_VARIABLE", "my_value", 1);

	if (result == 0)
	{
		printf("Environment variable modifier of added successfully");
	}
	else
	{
		printf("Failed to modify or add environment variable");
	}

	return (0);
}
