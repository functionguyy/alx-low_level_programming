#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * getFirstCharPosition - returns the pointer to first non-delimiter or
 * non-null byte character in a string
 * @startChar: pointer to the first character in the string
 * @delimChar: pointer to the delimiter character
 *
 * Return: returns pointer to the first non-delimiter or non-null byte
 * character in the string or NULL otherwise
 */
char *getFirstCharPosition(char *startChar, char *delimChar)
{
	/* declare variables */
	char *charInFirstPosition;

	/* initialize variables */
	charInFirstPosition = startChar;

	while (*charInFirstPosition == *delimChar)
		charInFirstPosition++;

	if (*charInFirstPosition == '\0')
		return (NULL);
	startChar = charInFirstPosition;

	return (startChar);
}
/**
 * charCount - counts the number of characters before the delimiter in a string
 * @str: pointer to the string
 * @delim: pointer to the delimiter character
 *
 * Return: returns the numbers characters before the delimiter or -1 otherwise
 */

int charCount(char *str, char *delim)
{
	/* declare variables */
	char *start, *scanner;
	static char *nextStart;
	int charCount;

	/* initialize variables */
	start = NULL;
	scanner = NULL;
	charCount = 0;

	if (str == NULL)
		start = nextStart;
	else
		start = str;

	if (*start == '\0')
		return (-1);

	/* skip spaces or empty strings */
	/* get point the first non-delim character in the string */
	scanner = getFirstCharPosition(start, delim);
	if (scanner == NULL)
		return (-1);

	/* count the non-null or non-space characters in the string */
	while (*scanner != *delim && *scanner != '\0')
	{
		charCount++;
		scanner++;
	}

	/* record to the next non-delimiter character in the string */
	nextStart = scanner;

	return (charCount);
}
/**
 * wordCount - counts the numbers of words delimited by a delimiter in a string
 * @str: pointer to the string
 * @delim: pointer to the delimiter character
 *
 * Return: returns the number of words in the string. This function doesn't
 * fail.
 */
int wordCount(char *str, char *delim)
{
	int count, endChecker;

	count = 0;
	endChecker = 0;


	endChecker = charCount(str, delim);
	while (endChecker != -1)
	{
		count += 1;
		endChecker = charCount(NULL, delim);
	}

	return (count);
}
/**
 * strTokenizer - breaks a string into a sequence of zero or more nonempty
 * tokens.
 * @str: pointer to the string
 * @delim: pointer the delimiter character
 *
 * Description: On the first call to strTokenzier(), the string to be parsed
 * should be specified in str. In each subsequent call that should parse the
 * same string, str must be NULL
 * Return: returns a pointer to the next token, or NULL if there are no more
 * tokens
 */
char *strTokenizer(char *str, char *delim)
{
	/* use the count to create array of pointers */
	static char *ptrRecord;
	int count;
	char *ptrToFirstChar, *start;


	count = 0;
	start = str;

	if (start == NULL)
		start = ptrRecord;

	if (*start == '\0')
		return (NULL);

	/* get the pointer to the first non-delim character */
	ptrToFirstChar = getFirstCharPosition(start, delim);
	if (ptrToFirstChar == NULL)
		return (NULL);


	/* return the count of characters in the word including the delimiter */
	count = charCount(ptrToFirstChar, delim);

	/* null terminate the word */
	if (*(ptrToFirstChar + count) == *delim)
	{
		*(ptrToFirstChar + count) = '\0';
		count++;
	}

	/* store the pointer to the next character after the null byte */
	ptrRecord = (ptrToFirstChar + count);

	return (ptrToFirstChar);
}
/**
 * strtow - splits a string into words
 * @str: pointer to strings
 *
 * Return: a pointer to an array of strings(words) or NULL otherwise
 */
char **strtow(char *str)
{
	/* declare variables */
	char *fullStr, *token, **ptrArr;
	int numberOfWords, arrIdx;

	/* initialize variables */
	fullStr = NULL;
	token = NULL;
	numberOfWords = 0;
	arrIdx = 0;

	/* confirm argument passed is not empty */
	if (str == NULL || *str == '\0')
		return (NULL);

	/* count the numbers of words in the string */
	numberOfWords = wordCount(str, " ");

	ptrArr = malloc(sizeof(char *) * (numberOfWords + 1));
	if (ptrArr == NULL)
		return (NULL);


	/* create a duplicate of the string */
	fullStr = strdup(str);

	token = strTokenizer(fullStr, " ");

	/* check that string contains atleast one non-delimiter character */
	if (strTokenizer == NULL)
		return (NULL);

	while (token != NULL)
	{
		ptrArr[arrIdx] = token;
		token = strTokenizer(NULL, " ");
		arrIdx++;
	}
	ptrArr[arrIdx] = NULL;
	return (ptrArr);
}

