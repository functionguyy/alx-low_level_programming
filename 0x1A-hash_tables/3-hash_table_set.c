#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key
 * @value: value associated with the key
 *
 * Description: function adds an element to the hash table. In case of
 * collision, it add the new element's node at the beginning of the singly
 * linked list
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *head, *new_node, *tmp;
	unsigned long int ht_array_idx;


	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);

	ht_array_idx = key_index((const unsigned char *)key, ht->size);
	head = ht->array[ht_array_idx];
	tmp = head;

	/* update value of existing key */
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	/* check if the array cell is empty */
	if (head == NULL)
	{
		ht->array[ht_array_idx] = new_node;
	}
	else
	{
		/* if collision occurs add new node to linked list */
		new_node->next = ht->array[ht_array_idx];
		ht->array[ht_array_idx] = new_node;
	}

	return (1);
}
/**
 * create_node - create a new node of a hash_node_t data structure
 * @key: value for hash_node_t key member
 * @value: value for hash_node_t value member
 *
 * Return: address to the new node or NULL if it fails
 */
hash_node_t *create_node(const char *key, const char *value)
{
	/* declare variables */
	hash_node_t *new_node = NULL;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	return (new_node);
}
