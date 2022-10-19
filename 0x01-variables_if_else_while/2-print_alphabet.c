#include <stdio.h>
/**
*main - Entry point of the program to print the letters of the alphabet
*
*Return:0(success)
*/
int main(void)
{
	char i;

	i = 'a';

	while (i <= 'z')
	{
		putchar(i);
		i++;
	}
	putchar('\n');
	return (0);
}
