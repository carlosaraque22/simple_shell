#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>

/**
 * struct shell -
 * @build:
 * @built:
 *
 */

typedef struct shell
{
	char *build;
	void (*built)(char **builds, char *array, char **end);
} shell_t
