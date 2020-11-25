#include "simple_shell.h"

/**
 * exit_simple_shell - This will run the builtin exit
 * @string: Line buffer of user input
 * @args: Arguments from user
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
 * env_simple_shell - Prints shell environment
 * @args: Arguments split from cmdline
 * @string: User input buffer
 * @env: Environment
 */
void env_simple_shell(char **args, char *string, char **env)
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
	(void)string;
}
