#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"


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
void simple_shell(void);
char *getline_v2(void);
void exit_simple_shell(char **builds, char *string, char **env);
char **split_line_v2(char *string);
int _strcmp(char *s1, char *s2);
void prompt(void);
int launch_prog(char **args);
int main(int arc, char **arv, char **env);
	
#endif
