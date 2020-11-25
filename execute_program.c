#include "simple_shell.h"

/**
 * execute_program - Executes binary or builtin
 * @args: Argument buffer
 * @string: Line buffer
 * @env: Environment
 * @flow: Helps decide what code to run
 * Return: 1 if success
 */

int execute_program(char **args, char *string, char **env, int flow)
{
	int status;

	if (args[0] == NULL)
		return (1);
	if (flow == 1)
	{
	if (check_for_builtin(args, string, env) == 1)
		return (1);
	}
	status = launch_prog(args);
	return (status);
}
