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
 * is_prime_number - function check if n is a prime number
 * @n: a whole number
 *
 * Return: 1 if n is a prime number or 0 otherwise
 */

int is_prime_number(int n)
{
	int odd, root, f;

	odd = 1;
	f = 2;
	root = _sqrt_checker(n, odd);

	if (root * root == n || n < 2)
		return (0);

	while (f < n)
	{
		if (n % f == 0)
			return (0);
		f++;
	}

	return (1);
}
