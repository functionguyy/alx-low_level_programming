#include "3-calc.h"
#include <stddef.h>
#include <string.h>
/**
* get_op_func - function that selects the correct function to perform the
* operation asked by the user
* @s: the operator passed as argument to the program
*
* Return: pointer to the function that corresponds to the operator given as a
* parameter or NULL if there is no operator match.
*/
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, s) == 0 && strlen(s) < 2)
		{
			return (ops[i].f);
		}
		else
		{
			printf("Error\n");
			exit(99);
		}
		i++;
	}
	return (ops[i].f);
}