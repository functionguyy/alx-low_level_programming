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
	hash_node_t *head, *new_node;
	unsigned long int ht_array_idx;


	if (ht == NULL || key == NULL)
		return (0);

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	ht_array_idx = key_index((const unsigned char *)key, ht->size);
	head = ht->array[ht_array_idx];

	/* check if the array cell is empty */
	if (head == NULL)
	{
		ht->array[ht_array_idx] = new_node;
	}
	else
	{
		/* check if the key already exit */
		if (strcmp(head->key, key) == 0)
		{
			strcpy(ht->array[ht_array_idx]->value, new_node->value);
		}
		else
		{
			/* if collision occurs add new node to linked list */
			new_node->next = ht->array[ht_array_idx];
			ht->array[ht_array_idx] = new_node;
		}

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
	char *new_key, *new_value;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	if (key)
	{
		new_key = strdup(key);
		if (new_key == NULL)
			return (NULL);
		new_value = strdup(value);
		if (new_value == NULL)
			return (NULL);
		new_node->key = new_key;
		new_node->value = new_value;
		new_node->next = NULL;
	}

	return (new_node);
}
