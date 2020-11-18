#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

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
