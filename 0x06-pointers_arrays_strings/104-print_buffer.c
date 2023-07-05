#include "main.h"
#include <stdio.h>
/**
 * print_buffer - Function that prints a buffer
 * @b: pointer to buffer to be printed
 * @size: size of bytes of the buffer
 *
 * Description: The function must print the content of `size` bytes of the
 * buffer pointed by `b`. The output should print 10bytes per line. Each line
 * starts with the position of the first byte of the line in hexadecimal (8
 * chars), starting with `0`. Each line shows the hexadecimal content (2 chars)
 * of the buffer, 2 bytes at a time, separated by a space. Each line shows the
 * content of the buffer. If the byte is a printable character, print the
 * letter, if not print `.`. Each line ends with a new line `\n`. You are
 * allowed to use the standard library.
 *
 * Return: Nothing
 */
void print_buffer(char *b, int size)
{
	int byte_idx, buf_idx, print_idx;

	for (buf_idx = 0; buf_idx < size; buf_idx += 10)
	{

		printf("%08x: ", buf_idx);

		for (byte_idx = 0; byte_idx < 10; byte_idx++)
		{
			print_idx = buf_idx + byte_idx;
			if (print_idx >= size)
				printf("  ");
			else
				printf("%02x", b[print_idx]);

			if ((byte_idx % 2) != 0 && byte_idx != 0)
				printf(" ");
		}

		for (byte_idx = 0; byte_idx < 10; byte_idx++)
		{
			print_idx = buf_idx + byte_idx;

			if (print_idx >= size)
				break;
			else if (b[print_idx] > 31 && b[print_idx] <= 126)
				printf("%c", b[print_idx]);
			else
				printf(".");
		}

		if (buf_idx >= size)
			continue;

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}
