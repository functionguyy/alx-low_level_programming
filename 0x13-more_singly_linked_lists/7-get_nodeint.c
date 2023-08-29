#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node of a singly linked list
 * @head: pointer to a singly linked list
 * @index: index of the node to be returned
 *
 * Description: index is the index of the node, starting at 0
 * Return: returns the nth node of a singly linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/* declare variables */
	size_t count, ncount;
	listint_t *nthNode;


	/* initialize variables */
	count = 0;
	ncount = 0;
	nthNode = NULL;

	if (head == NULL)
		return (nthNode);

	/* count the nodes in the singly linked list */
	ncount = listint_len(head);

	/* seek the nth node */
	while (count <= ncount)
	{
		nthNode = head;
		head = nthNode->next;
		if (count == index)
			break;
		count++;
	}

	return (nthNode);
}
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


	/* count the nodes in the singly linked list */
	while (h != NULL)
	{
		n++;
		h = h->next;
	}

	return (n);
}
