#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitString(const char *input, int *wordCount)
{
	int count = 0;
	int inWord = 0;
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			if (!inWord)
			{
				count++;
				inWord = 1;
			}
		}
	        else
		{
			inWord = 0;
		}
	}

	*wordCount = count;

	/* Reserva de memoria para arreglo de palabras  */
	char **words = (char **)malloc(*wordCount * sizeof(char *));
	if (words == NULL)
	{
		perror("Error when alloc memory");
		exit(EXIT_FAILURE);
	}

	/* Dividir cadena en palabras y agregarlos al arreglo  */
	char *copy = (char *)malloc(strlen(input) + 1);
	strcpy(copy, input);
	char *token = strtok(copy, " ");
	int index = 0;

	while (token != NULL)
	{
		words[index] = (char *)malloc(strlen(token) + 1);
		strcpy(words[index], token);
		token = strtok(NULL, " ");
		index++;
	}

	free(copy);

	return (words);
}

int main()
{
	int wordCount;
	char input[256];
	int i;

	printf("Ingresa un texto: ");
	fflush(stdout);

	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	char **words = splitString(input, &wordCount);

	for (i = 0; i < wordCount; i++)
	{
		printf("Palabra %d: %s\n", i + 1, words[i]);
		free(words[i]);
	}

	free(words);

	return (0);
}
