#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char *directory;
	struct Node *next;
};

struct Node *buildListDirectories()
{
	struct Node *init = NULL;
	char *path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not found");
		return NULL;
	}

	char *token = strtok(path, ":");
	struct Node *last = NULL;

	while (token != NULL)
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->directory = strdup(token);
		newNode->next = NULL;

		if (init == NULL)
		{
			init = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}

		token = strtok(NULL, ":");
	}

	return (init);
}

void freeList(struct Node *init)
{
	while (init != NULL)
	{
		struct Node *tmp = init;
		init = init->next;
		free(tmp->directory);
		free(tmp);
	}
}

int main()
{
	struct Node *init = buildListDirectories();

	if (init != NULL)
	{
		printf("List of directories in the PATH environment variable:\n");
		struct Node *current = init;

		while (current != NULL)
		{
			printf("%s\n", current->directory);
			current = current->next;
		}

		freeList(init);
	}

	return (0);
}
