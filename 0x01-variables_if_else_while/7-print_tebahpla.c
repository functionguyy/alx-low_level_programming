#include <stdio.h>
/**
*main - Entry point of the program that prints the lowercase alphabet in
*reverse followed by a new line
*Return:0 if successful
*/
int main(void)
{
	char i;

	i = 'z';
	while (i >= 'a')
	{
		putchar(i);
		i--;
	}
	putchar('\n');
	return (0);
}
