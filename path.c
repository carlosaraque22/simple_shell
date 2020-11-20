#include "simple_shell.h"
/**
 * look_path - this function look the path.
 * @filename: file name
 * @tmp: saves the PATH string
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
	file_path = strtok(tmp, ":");
	while (file_path)
	{
		dir = opendir(found_path);
		if (!dir)
		{
			printf("Error! Unable to open directory.\n");
			exit(0);
		}
	}
}
