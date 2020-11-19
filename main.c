#include "simple_shell.h"

/**
 * main - Entry point for simple shell.
 * @arc: number of arguments that have been entered.
 * @arv: array of character pointers.
 * @env: Environment of simple shell.
 * Return: 0.
 */
int main(int arc, char **arv, char **env)
{
	if (!arc)
		(void)arc;
	if (!arv)
		(void)arv;
	if (!env)
		(void)env;
	simple_shell(arc, arv, env);
	return (0);
}
