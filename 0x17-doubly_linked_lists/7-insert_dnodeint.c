#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - function that inserts a new node at a given
 * position
 * @h: pointer to the beginning of the list
 * @idx: the index of the list where the new node should be added. index starts
 * at 0
 * @n: node data integer value
 *
 * Description: inserts a new node at given position of a dlistint_t doubly
 * linked list.
 * if it is not possible to add the new node at index idx, do not add the new
 * node and return NULL
 * Return: the address of the new node or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *cur_node_at_idx_before = NULL;
	dlistint_t *new_node = NULL;

	if (h)
	{
		/* Add new node to beginning of list if given index is 0 */
		if (idx == 0)
		{
			return (add_dnodeint(h, n));
		}
		else
		{
			/* get the current node at index before given index in linked list */
			cur_node_at_idx_before = get_dnodeint_at_index(*h, (idx - 1));
			if (cur_node_at_idx_before == NULL)
				return (NULL);
		}

		/**
		 * Add new node to end of list if current node at index before given
		 * index is the last node of the list
		 */
		if (cur_node_at_idx_before->next == NULL)
			return (add_dnodeint_end(&cur_node_at_idx_before, n));

		new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		new_node->next = cur_node_at_idx_before->next;
		cur_node_at_idx_before->next->prev = new_node;
		new_node->prev = cur_node_at_idx_before;
		cur_node_at_idx_before->next = new_node;

		return (new_node);
	}
	return (NULL);
}

/**
 * get_dnodeint_at_index - function retuns the nth node of a dlistint_t linked
 * list
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
