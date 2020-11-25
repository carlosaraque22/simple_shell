#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"
extern char **environ;


/**
 * struct shell - Has builtins and associated funcs
 * @ar: Builtins name
 * @built: Mathcing builtin func
 */

typedef struct shell
{
	char *ar;
	void (*built)(char **args, char *string, char **env);
} shell_t;

void simple_shell(int ac, char **av, char **env);
char *getline_v2(void);
void exit_simple_shell(char **args, char *string, char **env);
void env_simple_shell(char **args, char *string, char **env);
char **split_line_v2(char *string);
int _strcmp(char *s1, char *s2);
void prompt(void);
int launch_prog(char **args);
int check_for_builtin(char **args, char *string, char **env);
int execute_program(char **args, char *string, char **env, int flow);
char *_strstr(char *haystack, char *needle);
int _strlen(char *c);
int builtin_checker(char **args);
char *_getenv(char *env);
int builtin_caller(char *check, char **args);
char *cwd(char *file, char *mistake);
char *save_path(char *tmp, char *path);
char *read_dir(char *mistake, struct dirent *s, char *fil, int l, char *fp, char *t);
char *look_path(char *filename, char *tmp, char *mistake);
void ctrl_c(int i);
void help_function(char **args, char *string, char **env);
#endif
