#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

#define LINE_SIZE 1024

/**
 * shell - Infinite loop that runs shell
 * Return: Void
 */

void simple_shell(void)
{
	char *string;
	char **env;
	int status;

	do {
		write(1, "$ ", 2);
		string = _getline_v2();
		env = split_line_v2(string);
		status = launch_prog(env);
		free(string);
		free(env);
	} while (status);
}
