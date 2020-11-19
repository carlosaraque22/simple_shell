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
	char **args;
	int status;
	
	do {
		write(1, "$ ", 2);
		string = getline_v2();
		args = split_line_v2(string);
		if (check_for_builtins(args, string) == 1)
			continue;
		status = launch_prog(args);
		free(string);
		free(args);
	} while (status);
}
