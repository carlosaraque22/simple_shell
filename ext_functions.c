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
