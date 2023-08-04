#include "main.h"
#include <string.h>
/**
 * _palindrome_helper - function that performs a palindrome test on a string
 * @s: pointer to the string to be checked
 * @start: integer represent the position of character from the beginning of s
 * @end: integer representing the position of character for the end of s
 *
 * Return: 1 if string is a palindrome or 0 otherwise
 */

int _palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	else if (s[start] != s[end])
		return (0);
	else
		return (_palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - function that checks if a string is a palindrome
 * @s: pointer to the string to be checked
 *
 * Return: 1 if string is a palindrome or 0 otherwise
 */

int is_palindrome(char *s)
{
	int start, end, r_val;

	start = 0;
	end = strlen(s) - 1;

	if (s == NULL)
		return (0);
	if (*s == '\0')
		return (1);


	r_val = _palindrome_helper(s, start, end);


	return (r_val);
}






