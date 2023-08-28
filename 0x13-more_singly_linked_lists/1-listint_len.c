#include "lists.h"
/**
 * listint_len - returns the number of elements in a singly linked list
 * @h: pointer to the singly linked list
 *
 * Description: returns the number of elements in a linked listint_t list
 * Return: returns the number of elements in a singly linked list
 */
size_t listint_len(const listint_t *h)
{
	/* declare variables */
	size_t n;

	/* initialize variables */
	n = 0;

	while (h != NULL)
	{
		n++;
		h = h->next;
	}

	return (n);
}
