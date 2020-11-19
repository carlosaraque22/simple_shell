#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"


/**
 * struct shell -
 * @build:
 * @built:
 *
 */

typedef struct builtins
{
	char *arg;
	void (*builtin)(char **args, char *line, char **env);
} builtins_t;
void simple_shell(void)
char *getline_v2(void)
void exit_simple_shell(char **builds, char *string, char **env)
char **split_line_v2(char *string);
int _strcmp(char *s1, char *s2);
void prompt(void);

#endif
