#include "simple_shell.h"
/**
 * look_path - this function look the path.
 * @filename: file name
 * @tmp: saves the PATH string.
 * @mistake: the error message.
 * Return: Success - path/filename, if fail return mistake
 */

char *look_path(char *filename, char *tmp, char *mistake)
{
	DIR *dir;
	struct dirent *sd;
	char *found_path, *path, *ret;
	int len = 0;

	while (filename[len])
		len++;
	path = _getenv("PATH");
	tmp = save_path(tmp, path);
	found_path = strtok(tmp, ":");
	while (found_path)
	{
		dir = opendir(found_path);
		if (!dir)
		{
			printf("Error! Unable to open directory.\n");
			exit(0);
		}
		while ((sd = readdir(dir)))
		{
			ret = read_dir(mistake, sd, filename, len, found_path, tmp);
			if (ret != mistake)
			{
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
			}
		}
		closedir(dir);
		found_path = strtok(NULL, ":");
	}
	path = NULL;
	free(tmp);
	return (mistake);
}
/**
 *read_dir - opens and reads directory file names in search of fil
 *@mistake: this is the error mensage for the path.
 *@s: struct containing info about a files in a directory.
 *@fil: name of file being searched for.
 *@fp: directory being searched through.
 *@t: string containing the PATH variable's value.
 *@l: length of filename.
 *Return: success - path of fil/fil, or mistake if fails.
 */
char *read_dir(char *mistake, struct dirent *s, char *fil, int l, char *fp, char *t)
{
	int i = 0;
	char *ret;

	for (i = 0; s->d_name[i] && fil[i]; i++)
	{
		if (s->d_name[i] != fil[i])
			break;
		if (i == (l - 1) && !(s->d_name[i + 1]))
		{
			ret = strcat(fp, "/");
			ret = strcat(ret, fil);
			free(t);
			return (ret);
		}
	}
	return (mistake);
}

/**
 *save_path - saves a copy of the PATH string
 *@tmp: copy to be made of PATH
 *@path: string containing original PATH value
 *
 *Return: tmp if success first time, path every other time, or mistake if fails.
 */
char *save_path(char *tmp, char *path)
{
	int i = 0;

	if (!tmp)
	{
		tmp = malloc(sizeof(char) * 100);
		while (path[i])
		{
			tmp[i] = path[i];
			i++;
			tmp[i] = '\0';
		}
		i = 0;
		return (tmp);
	}
	else
	{
		while (tmp[i])
		{
			path[i] = tmp[i];
			i++;
			path[i] = '\0';
		}
		i = 0;
		return (path);
	}
	return ("error");
}
