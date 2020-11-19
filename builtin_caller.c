#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * builtin_caller - Will check to see whether we are dealing with a builtin or not
 * @check: Figures out what to execute
 * Return: 1 if user entered a path/builtin, 2 if user entered a binary
 */

int builtin_caller(char *check, char **args, char *line)
{
	int i = 0;

	if (builtin_checker(args, line) == 1)
		return (1);
	while (check[i] != '\0')
	{
		if (check[i] == '/')
			return (1);
		i++;
	}
	return (2);
}