#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename1> [<filename2> ...]\n", argv[0]);
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		const char *filename = argv[i];
		struct stat file_info;

		if (stat(filename, &file_info) == 0 && S_ISREG(file_info.st_mode))
		{
			printf("%s: Found\n", filename);
		}
		else
		{
			printf("%s: Not Found\n", filename);
		}
	}

	return (0);
}
