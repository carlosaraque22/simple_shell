#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>

typedef struct built_in
{
	char *build;
	void (*built)(char **builds, char *array, char **end);
} built_in_t
