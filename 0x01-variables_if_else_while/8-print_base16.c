#include <stdio.h>
/**
*main - Enrty point of the program
*Return: 0 if succesful
*/
int main(void)
{
	char i;
	char I;

	i = 48;
	I = 'a';
	while (i <= 57)
	{
		putchar(i);
		i++;
	}
	while (I <= 'f')
	{
		putchar(I);
		I++;
	}
	putchar('\n');
	return (0);

}
