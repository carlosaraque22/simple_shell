#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#define LINE_SIZE 1024

/**
 * struct shell -
 * @build:
 * @built:
 *
 */

typedef struct shell
{
	char *build;
	void (*built)(char **builds, char *string, char **env);
} shell_t

#endif
