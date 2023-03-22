#include "lists.h"
#include  <stdlib.h>
/**
 * delete_dnodeint_at_index - function that deletes the node at index of a
 * dlistint_t linked list
 * @head: pointer to pointer to the beginning of the list
 * @index: index of the node that should be deleted.
 *
 * Description: dlistint_t is a doubly linked list
 * Return: 1 if it succeeded or -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur = NULL;
	size_t list_node_count = 0;

	if (head != NULL && *head != NULL)
	{
		cur = *head;
		/* delete first node in the list */
		if (index == 0)
		{
			*head = cur->next;
			cur->next->prev = cur->prev;
		}
		else
		{
			/* Get total length of the list */
			list_node_count = dlistint_len(*head);

			/* if index is out of list range */
			if (index >= list_node_count)
				return (-1);

			else if (index <= list_node_count - 1)
			{
				/* delete node in the middle of the list */
				cur = get_dnodeint_at_index(*head, index);
				cur->prev->next = cur->next;
				if (cur->next != NULL)
					cur->next->prev = cur->prev;
			}
		}
		free(cur);
		return (1);
	}
	return (-1);
}

/**
 * dlistint_len - function that returns the number of element in a linked
 * dlistint_t list
 * @h: head pointer of dlistint_t list
 *
 * Return: the number of nodes in the list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t node_count;

	node_count = 0;

	if (h)
	{
		while (h != NULL)
		{
			node_count++;
			h = h->next;
		}
	}
	return (node_count);
}

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
				return (cur_node);
			count++;
		}
	}
	return (NULL);
}
