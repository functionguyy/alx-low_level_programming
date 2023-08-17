#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * op_add - function returns sum of a and b
 * @a: integer
 * @b: integer
 *
 * Return: returns sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - function returns the difference of a and b
 * @a: integer
 * @b: integer
 *
 * Return: returns the difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - function returns the product of a and b
 * @a:integer
 * @b:integer
 *
 * Return: returns the product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - function returns the result of the division of a by b
 * @a: integer
 * @b: integer
 *
 * Return: return result of the division of a by b
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}
/**
 * op_mod - function return the remainder of the division of a by b
 * @a: integer
 * @b: integer
 *
 * Return: returns the remainder of the division of a by b
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
