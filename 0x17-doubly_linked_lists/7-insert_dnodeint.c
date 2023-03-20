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
	dlistint_t *cur_node_at_idx = NULL;
	dlistint_t *new_node_to_tail = NULL;
	dlistint_t *temp = NULL;

	if (h && (idx >= 0))
	{
		/* slice the current node at given index from linked list */
		cur_node_at_idx = get_dnodeint_at_index(*h, idx);
		if (cur_node_at_idx == NULL)
			return (NULL);

		/* save node before current node at given index */
		temp = cur_node_at_idx->prev;

		/* Add new node  and connect it to the current node at given position */
		new_node_to_tail = add_dnodeint(&cur_node_at_idx, n);
		if (new_node_to_tail == NULL)
			return (NULL);


		/*connect the new node to node before former node at given position */
		if (idx == 0)
		{
			return (new_node_to_tail);
		}
		else
		{
			new_node_to_tail->prev = temp;
			temp->next = new_node_to_tail;
		}

		return (new_node_to_tail);
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

