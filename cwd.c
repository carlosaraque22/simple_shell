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
	/* take the lenght of file */
	ret = malloc(sizeof(char) * (len + 3));
	/* add 3 to len because its considering the ./ and null char */
	dir = opendir(".");
	/* enter into the current directory and returns a pointer */
	if (!dir)
	{
		printf("Error! Unable to open directory.\n");
		exit(0);
	}
	while ((sd = readdir(dir)))
/*reads the DIR pointer and returns the pointer structure, check all the files in dir*/
	{
		for (i = 0; sd->d_name[i] && file[i]; i++)
			/* first condition check all the directories, files in the dir*/
			/* second condition check the content inside of the files, directories */
		{
			if (sd->d_name[i] != file[i])
				break;
			/* checks if has something inside, if it does not have, error */		
			if (i == (len - 1) && (sd->d_name[i + 1]))
				/* takes all the lenght and position the pointer in the first position */
			{
				strcpy(ret, "./");
				strcat(ret, file);
				/* concat the ./ and the file */
				closedir(dir);

				if (!(access(ret, X_OK)))
					/* check for permissions */
					return (ret);
					write(2, mistake, 5);
			}
		}
	}
	closedir(dir);
	return (mistake);
}
