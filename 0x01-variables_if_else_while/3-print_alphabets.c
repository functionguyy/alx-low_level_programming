#include <stdio.h>
/**
*main - Entry point of the program that prints the alphabet in lowercase and
*then in uppercase
*Return: 0 if successful
*/
int main(void)
{
	char i;
	char I;

	i = 'a';
	I = 'A';
	while (i <= 'z')
	{
		putchar(i);
		i++;
	}
	while (I <= 'Z')
	{
		putchar(I);
		I++;
	}
	putchar('\n');
	return (0);
}
