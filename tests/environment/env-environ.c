#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main()
{
	printf("Direccion de environ: %p\n", (void *)environ);

	return (0);
}
