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
	char **end;
	int status;

	do {
		write(1, "$ ", 2);
		string = _getline_v2();
		end = split_line(line);
		status = launch_prog(end);
		free(string);
		free(end);
	} while (status);
}
