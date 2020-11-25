#include "simple_shell.h"
/**
 * _getenv - gets env of input.
 * @env: this is the input.
 * environ: points to the unistd.h environment
 * temp: saves environ to variable result.
 * res: compares the environment input until first occurence (slash).
 * Return: the env.
 */

char *_getenv(char *env)
{
	int i = 0, n = 0;
	char *temp, *res;

	while (i = 0; environ[i] != NULL; i++)
	{
		n (_strlen(environ[i]));
		write(1, environ[i], n);
		write(1, "\n", 1);
	}

	return (0);
}
