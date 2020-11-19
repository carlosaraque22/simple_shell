#include "simple_shell.h"

/**
 * main - Entry point for simple shell.
 * @ac: number of arguments that have been entered.
 * @av: array of character pointers.
 * @env: Environment of simple shell.
 * Return: 0.
 */
int main(int ac, char **av, char **env)
{
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	if (!env)
		(void)env;
	shell(ac, av, env);
	return (0);
}
