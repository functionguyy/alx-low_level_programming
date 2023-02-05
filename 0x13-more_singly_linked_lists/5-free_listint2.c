#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
/**
* free_listint2 - function frees a listint_t list.
* @head: pointer to the pointer to the head of the list
*
* Return: Nothing
*/
void free_listint2(listint_t **head)
{
	listint_t *cur_node;

	if (*head == NULL)
	{
		exit(EXIT_FAILURE);

	}

	while (*head != NULL)
	{
		cur_node = *head;
		*head = cur_node->next;
		free(cur_node);
	}
	free(*head);
	*head = NULL;
}
