#include "main.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
/**
 * copy - function that copies the content of two strings into the same memory
 * space
 * @memory: memory space
 * @tLen: total number of bytes in both strings excluding their terminating
 * null byte
 * @st1: pointer to the first string
 * @st2: pointer to the second string
 * @s1Len: number of bytes in the first string excluding the terminating null
 * byte
 * @s2Len: number of bytes in the second string excluding the terminating null
 * byte
 *
 * Return: Nothing
 */

void copy(char *memory, int tLen, char *st1, char *st2, int s1Len, int s2Len)
{
	/* Declare variables */
	int loopIndex, str1Count, str2Count;
	bool strSwitch;

	/* initialize variable */
	loopIndex = 0;
	str1Count = 0;
	str2Count = 0;
	strSwitch = false;


	/* assign character in string pointed to by str1 and str2 to new memory */
	while (loopIndex < tLen)
	{
		if (strSwitch == false && str1Count < s1Len)
			memory[loopIndex] = st1[str1Count];

		if (str1Count == s1Len && strSwitch == false)
			strSwitch = true;

		if (strSwitch == true && str2Count < s2Len)
			memory[loopIndex] = st2[str2Count];

		if (strSwitch == false)
			str1Count++;
		else
			str2Count++;

		loopIndex++;
	}

	/* assign string terminating NULL byte */
	memory[loopIndex] = '\0';
}

/**
 * str_concat - function that concatenates two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: pointer to a newly allocated space in memory which contains the
 * contents of s1, followed by the contents of s2 or NULL otherwise
 */

char *str_concat(char *s1, char *s2)
{
	/* Declare variables */
	char *newStrMemory;
	int str1Len, str2Len, totalLen;

	/* initialize variables */
	newStrMemory = NULL;
	errno = 0;

	/**
	 * confirm NULL is passed as value for s1 or s2 and
	 * treat it as empty string
	 */
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/* get the total length of the strings pointed to by s1 and s2 */
	str1Len = strlen(s1);
	str2Len = strlen(s2);
	totalLen = str1Len + str2Len;

	/* use total length of both strings to request memory allocation */
	newStrMemory = malloc(sizeof(char) * totalLen + 1);

	/* confirm that memory allocation failed */
	if (errno == ENOMEM)
		return (NULL);


	/* assign characters in string pointed to by s1 and s2 to the new memory */
	copy(newStrMemory, totalLen, s1, s2, str1Len, str2Len);

	/* return pointer to newly allocated memory */
	return (newStrMemory);
}




