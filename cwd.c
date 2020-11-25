#include "simple_shell.h"
/**
 * cwd - search the current working directory.
 * @file: this is the file name.
 * @mistake: the error output.
 * Return: the current working dir.
 */

char *cwd(char *file, char *mistake)
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
	while ((sd = readdir(dir)))
	{
		for (i = 0; sd->d_name[i] && file[i]; i++)
		{
			if (sd->d_name[i] != file[i])
			{
				break;
			}
			if (i == (len - 1) && !(sd->d_name[i + 1]))
			{
				strcpy(ret, "./");
				strcat(ret, file);
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
			}
			else
				write(2, mistake, 5);
		}
	}
	closedir(dir);
	return (mistake);
}
