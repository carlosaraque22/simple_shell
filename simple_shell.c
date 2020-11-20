#include "simple_shell.h"

/**
 * simple_shell - Infinite loop that runs shell
 * @ac: Arg count
 * @av: args passed to shell at beginning of prog
 * Return: Void
 */

void simple_shell(int ac, char **av, char **env)
{
	char *string;
	char **args;
	int status = 1;
	char *mistake;
	char *file;
	int flow;
        mistake = "error";

	do {
		prompt();
		string = getline_v2();
		args = split_line_v2(string);
		flow = builtin_caller(args[0], args);
		if (flow == 2)
		{
			file = args[0];
			if (args[0] == mistake)
			{
				args[0] = cwd(file, mistake);
				if (args[0] == file)
					write(1, mistake, 5);
			}
		}
		if (args[0] != mistake)
			status = execute_program(args, string, env, flow);
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
