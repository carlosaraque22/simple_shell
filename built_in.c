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
 * @string: Line user buffer imput.
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
/**
 * fcd - command cd function
 * @args: arguments
 * @env: environment variables
 * @string: user buffer
 * Return: void
 */
void cd_function(char **args, char *string, char **env)
{
	char *path = "HOME=";
	char *tmp = NULL;
	int i, j, k;

	if (args[1] == NULL)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (path[j] != env[i][j])
					break;
			}
			if (j == 5)
				break;
		}
		tmp = malloc(_strlen(env[i]) + 1);
		if (tmp == NULL)
			perror("");
		for (k = 0; env[i][j] != '\0'; j++, k++)
			tmp[k] = env[i][j];
		if (chdir(tmp) != 0)
		{
			free(tmp);
			perror("");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			free(tmp);
			perror("");
		}
	}
	if (!args)
		(void)args;
	if (!string)
		(void)string;
}
