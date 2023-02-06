#include <stddef.h>
#include <stdlib.h>
#include "lists.h"
/**
* pop_listint - function that deletes the head node of a listint_t linked list
* @head: pointer to the pointer that points to the list
*
* Return: head node data or 0 if list is empty
*/
int pop_listint(listint_t **head)
{
	int n;
	listint_t *cur_node;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}
	while (*head != NULL)
	{
		cur_node = *head;
		n = cur_node->n;
		*head = cur_node->next;
		free(cur_node);
		break;
	}
	return (n);
}
