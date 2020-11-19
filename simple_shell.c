#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define LINE_SIZE 1024
#define TOKENS_BUFFER_SIZE 64
/**
 * shell - Infinite loop that runs shell
 * @ac: Arg count
 * @av: args passed to shell at beginning of prog
 * Return: Void
 */

void simple_shell(int ac, char **av, char **env)
{
	char *string;
	char **args;
	int status = 1;
	char *tmp = NULL;
	char *er;
	char *filename;
	int flow;
	er = "error";
	do {
		write(1, "$ ", 2);
		string = _getline_v2();
		args = split_line_v2(string);
		flow = bridge(args[0], args);
		if (flow == 2)
		{
			filename = args[0];
			args[0] = find_path(args[0], tmp, er);
			if (args[0] == er)
			{
				args[0] = search_cwd(filename);
			}
		}
		status = execute_program(args, string, env);
		free(string);
		free(args);
	} while (status);
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
}
