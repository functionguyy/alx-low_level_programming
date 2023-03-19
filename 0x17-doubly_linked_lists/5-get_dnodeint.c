#include <stdlib.h>
#include "lists.h"
/**
 * get_dnodeint_at_index - function that returns the nth node of a dlistint_t
 * linked list
 * @head: pointer to the beginning of the list
 * @index: the index of the node, starting from 0
 *
 * Return: the address of the nth node or NULL if node does not exist
 */


dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count;
	dlistint_t *cur_node;

	cur_node = NULL;
	count = 0;

	if (head)
	{
		while (head->next != NULL)
		{
			cur_node = head;
			if (count == index)
				break;

			head = cur_node->next;
			count++;
		}
		return (cur_node);
	}
	return (NULL);
}
