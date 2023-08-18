#include <stdio.h>
#include <stdlib.h>

int main()
{
	int result = setenv("PERSONAL_VARIABLE", "my_value", 1);

	if (result == 0)
	{
		printf("Environment variable modified or added successfully\n");
	}
	else
	{
		printf("Failed to modify or add environment variable\n");
	}

	return (0);
}
