#include "3-calc.h"
#include <stddef.h>
#include <string.h>
/**
 * get_op_func - function that selects the correct function to perform the
 * operation asked by the user
 * @s: pointer to the operator passed as argument to the program
 *
 *
 * Return: pointer to the function that corresponds to the operator given as a
 * parameter or NULL if there is no operator match
 */
int (*get_op_func(char *s))(int, int)
{
	/* declare variables */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	/* initialize variable */
	i = 0;

	/* get function based on operator passed */
	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, s) == 0 && strlen(s) < 2)
		{
			return (ops[i].f);
		}
		i++;
	}

	return (NULL);
}
