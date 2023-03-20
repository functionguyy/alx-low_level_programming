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
	dlistint_t *head = *h;

	if (h && (idx >= 0))
	{
		/* take the list to the beginning */
		while (head->prev != NULL)
		{
			head = head->prev;
		}

		if (idx == 0)
			return (add_dnodeint(&head, n));

		/* get the current node at index before given index from linked list */
		cur_node_at_idx_before = get_dnodeint_at_index(head, (idx - 1));
		if (cur_node_at_idx_before == NULL)
			return (NULL);

		/* save address of current node at given index */
		temp = cur_node_at_idx_before->next;
		/*break the linked list to create entry point for new node */
		cur_node_at_idx_before->next = NULL;

		/* Add new node  and connect it to the node before given idx*/
		new_node_at_given_idx = add_dnodeint_end(&cur_node_at_idx_before, n);
		if (new_node_at_given_idx == NULL)
			return (NULL);

		/*connect the new node to previous node at given position */
		new_node_at_given_idx->next = temp;
		temp->prev = new_node_at_given_idx;

		return (new_node_at_given_idx);
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

