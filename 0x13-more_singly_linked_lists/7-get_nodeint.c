#include "lists.h"
#include <stdio.h>
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
	unsigned int count;
	listint_t *nthNode;


	/* initialize variables */
	count = 0;
	nthNode = NULL;


	/* seek the nth node */
	while (head != NULL)
	{
		nthNode = head;
		head = nthNode->next;
		if (count == index)
			return(nthNode);
		count++;
	}

	return (NULL);
}
