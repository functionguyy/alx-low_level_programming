#include "main.h"
/**
 * _sqrt_checker - function that performs repeated subtraction of consecutive
 * odd numbers from num till the result is either 0 or less that zero
 * @num: a whole number
 * @odd: a positive odd number
 *
 * Description: The function count how many steps it takes for the result of
 * the subtraction reach 0 or less than zero (which ever comes first)
 * Return: the number of subtraction steps or zero
 */

int _sqrt_checker(int num, int odd)
{
	if (num < 0)
		return (-1);
	else if (num == 0)
		return (0);
	else
		return (1 + _sqrt_checker((num - odd), (odd + 2)));
}

/**
 * _sqrt_recursion - function that returns the non-negative square root of a
 * number
 * @n: a whole number
 *
 * Return: natural square root or -1
 */

int _sqrt_recursion(int n)
{
	int odd, root;

	odd = 1;
	root = _sqrt_checker(n, odd);

	if (root * root != n)
		return (-1);

	return (root);
}
