#include <stdlib.h>
#include "lists.h"
/**
* free_listint - function frees a listint_t list
* @head: pointer to listint_t list
*
* Return: Nothing
*/
void free_listint(listint_t *head)
{
	listint_t *cur_node;


	while (head != NULL)
	{
		cur_node = head;
		head = cur_node->next;
		free(cur_node);
	}
	free(head);
}
