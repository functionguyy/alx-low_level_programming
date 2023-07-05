#include "main.h"
#include <string.h>
#include <stdio.h>
void rev_string(char *s);
/**
 * infinite_add - Function that adds two numbers
 * @n1: string literal representation of the first number
 * @n2: string literal representation of the second number
 * @r: the buffer that the function will use to store the result
 * @size_r: the buffer size
 *
 * Description: You can assume that you will always get positive numbers, or
 *
 * Return: pointer to the result or 0 if result can be stored
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l_n1, l_n2, t_total, x, y;
	int carry_over, t_n1, t_n2, res_idx;


	l_n1 = strlen(n1) - 1;
	l_n2 = strlen(n2) - 1;
	carry_over = 0;
	res_idx = 0;


	if (l_n1 >= size_r || l_n2 >= size_r)
		return (0);

	for (x = l_n1, y = l_n2; x >= 0 || y >= 0 || carry_over == 1; x--, y--)
	{
		if (x < 0)
			t_n1 = 0;
		else
			t_n1 = n1[x] - '0';

		if (y < 0)
			t_n2 = 0;
		else
			t_n2 = n2[y] - '0';


		t_total = t_n1 + t_n2 + carry_over;
		if (t_total > 9)
			carry_over = 1;
		else
			carry_over = 0;

		if (res_idx >= (size_r - 1))
			return (0);

		r[res_idx] = (t_total % 10) + '0';

		res_idx++;
	}
	if (res_idx == size_r)
		return (0);
	r[res_idx] = '\0';

	rev_string(r);
	return (r);
}

/**
 * rev_string - reverse a string
 * @s: char array string type
 *
 * Return - Nothing
 */

void rev_string(char *s)
{
	int i;
	int j;
	char c;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	j = i - 1;
	i = 0;
	while (i < j)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;

		i++;
		j--;
	}
}
