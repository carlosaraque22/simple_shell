#include "simple_shell.h"

/**
 * _getline - Gets line of user input
 * Return: Pointer to buffer of user input
 */
char *getline_v2(void)
{
	int tmp;
	char *string;
	size_t size = 0;

	tmp = getline(&string, &size, stdin);
	if (tmp == EOF)
	{
		write(1, "\n", 1);
		exit(1);
	}
	return (string);
}

/**
 * split_line - Splits line into args
 * @string: Line of user input
 * Return: Array of args of user input
 */
char **split_line_v2(char *string)
{
	size_t buffer_size = TOKENS_BUFFER_SIZE;
	char **tokens = malloc(sizeof(char *) * buffer_size);
	char *token;
	int pos = 0;
	if (!tokens)
	{
		perror("Could not allocate space for tokens\n");
		exit(2);
	}
	token = strtok(string, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[pos] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
		pos++;
	}
	tokens[pos] = NULL;
	return (tokens);
}

/**
 * check_for_builtins - Checks for builtins.
 * @args: The arguments passed from prompt.
 * @line: The buffer with line of input from user.
 * @env: Environment of simple shell.
 * Return: 1 if builtins exist, or 0 if not.
 */

int builtin_checker(char **args, char *string, char **env)
{
	shell_t list[] = {
		{"exit", exit_shell},
		{"env", env_shell},
		{NULL, NULL}
	};
	int i;

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (_strcmp(list[i].arg, args[0]) == 0)
		{
			list[i].builtin(args, string, env);
			return (1);
		}
	}
	return (0);
}

/**
 * launch_prog - Forks and launches unix cmd.
 * @args: The arguments for cmd.
 * Return: Always 1 (success).
 */

int launch_prog(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Failed to execute command\n");
			exit(3);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking\n");
		exit(4);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	(void)wpid;
	return (1);
}
