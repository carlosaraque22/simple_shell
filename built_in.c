#include "simple_shell.h"

/**
 * exit_simple_shell - This will run the builtin exit
 * @string: Line buffer of user input
 * @builds: Arguments from user
 * @env: Environment
 * Return: Void
 */

void exit_simple_shell(char **args, char *string, char **env)
{
	free(args);
	free(string);
	(void)env;
	exit(0);
}
/**
 * env_shell - Prints shell environment
 * @args: Arguments split from cmdline
 * @line: User input buffer
 * @env: Environment
 */
void env_shell(char **args, char *line, char **env)
{
	int size, i = 0;

	while (env[i] != NULL)
	{
		size = _strlen(env[i]);
		write(1, env[i], size);
		write(1, "\n", 1);
		i++;
	}
	(void)args;
	(void)line;
}
