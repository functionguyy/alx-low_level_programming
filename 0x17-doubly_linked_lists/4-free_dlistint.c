#include <stdlib.h>
#include "lists.h"
/**
 * free_dlistint - function that free a dlistint_t list
 * @head: pointer to the beginning of the list
 *
 * Return: Nothing
 */


void free_dlistint(dlistint_t *head)
{
	dlistint_t *cur_node;

	if (head)
	{
		while (head->next != NULL)
		{
			cur_node = head;
			head = cur_node->next;
			free(cur_node);
		}
		free(head);

	}
}
