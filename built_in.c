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
 * env_simple_shell - Prints shell environment
 * @args: Arguments split from cmdline
 * @line: User input buffer
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
/**
 * ctrl_c- function for use ctrl c in c.
 * @i: the line string.
 * Return: the return is void
 */
void ctrl_c(int i)
{
	(void)i;
	signal(SIGINT, ctrl_c);
	write(1, "\n", 1);
	prompt();
}
/**
 * help_function - command that add help function.
 * @args: the arguments passed from the imput.
 * @env: environment variables.
 * Return: is not neccessary.
 */
void help_function(char **args, char *string, char **env)
{
	(void)env;
	if (args[1] != NULL)
	{
		if (execve("/bin/cat", args, NULL) == -1)
		{
			perror("");
		}
		printf("a!\n");
	}
	(void)string;
	printf("HELP!\n");
}
