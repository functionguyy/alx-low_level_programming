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

	count = 0;
	cur_node = NULL;

	if (head)
	{
		while (head != NULL)
		{
			cur_node = head;
			head = cur_node->next;
			if (count == index)
				break;
			count++;
		}
		return (cur_node);
	}
	return (NULL);
}
