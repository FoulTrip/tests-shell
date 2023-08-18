#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_getenv(const char *name)
{
	int i;
	extern char **environ;
	int len_name = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], len_name) == 0 && environ[i][len_name] == '=')
			return (environ[i] + len_name + 1);
	}

	return (NULL);
}

int main()
{
	char *path_value = _getenv("PATH");

	if (path_value != NULL)
	{
		printf("Valor de PATH: %s\n", path_value);
	}
	else
	{
		printf("Variable de entorno PATH no encontrada\n");
	}

	return (0);
}
