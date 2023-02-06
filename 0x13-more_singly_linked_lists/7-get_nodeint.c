#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
/**
* get_nodeint_at_index - function returns the nth node of a listint_t linked
* list
* @head: pointer to the list
* @index: index of the node starting
*
* Return: pointer to the address of nth node or NULL if node does not exist.
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *cur_node;
	unsigned int elem_count;

	elem_count = 0;
	if (head)
	{
		while (head != NULL)
		{
			cur_node = head;
			head = cur_node->next;
			if (elem_count == index)
			{
				return (cur_node);
			}
			elem_count++;
		}
	}
	return (NULL);
}
