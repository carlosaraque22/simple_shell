#include "simple_shell.h"
/**
 * check_wd - check if there is an executable file.
 * @file: this is the file name.
 * @mistake: the error.
 * Return: the current working dir.
 */

char *check_wd(char *file, char *mistake)
{
	DIR *dir;
	struct dirent *sd;
	char *ret;
	int len = 0, i = 0;

	while (file[len])
		len++;
	ret = malloc(sizeof(char) * (len + 3));

	dir = opendir(".");
	if (!dir)
	{
		printf("Error! Unable to open directory.\n");
		exit(0);
	}
	while ((sd = readdir(dir))) /* check all the files in dir */
	{
		for (i = 0; sd->d_name[i] && file[i]; i++)
       /* first condition check all the directories, files in the dir*/
     /* second condition check the content inside of the files, directories */
		{
			if (sd->d_name[i] != file[i])
				break;
			if (i == (len - 1) && (sd->d_name[i + 1]))
      /* takes all the lenght and position the pointer in the first position */
			{
				strcpy(ret, "./");
				strcat(ret, file);
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
					write(2, mistake, 5);
			}
			perror("");
			exit(127);
		}
	}
	closedir(dir);
	return (mistake);
}
