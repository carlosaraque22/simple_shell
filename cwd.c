#include "shell.h"
/**
 * cwd - search the current working directory.
 * @file: this is the file name.
 * Return: the current working dir.
 */

char cwd(char *file, char *er)
{
	DIR *dir;
	struct dirent *sd;
	char *ret;
	int len = 0;
	int i = 0;

	while (file[len])
		len++;
	ret = malloc(sizeof(char) * (len + 3));
	dir = opendir(".");
	if (!dir)
	{
		printf("Error! Unable to open directory.\n");
		exit(0);
	}
	return (er);
}
