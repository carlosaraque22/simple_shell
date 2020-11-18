#include "simple_shell.h"

/**
 * exit_simple_shell - This will run the builtin exit
 * @string: Line buffer of user input
 * @builds: Arguments from user
 * @env: Environment
 * Return: Void
 */

void exit_simple_shell(char **builds, char *string, char **env)
{
	free(builds);
	free(string);
	(void)env;
	exit(0);
}
