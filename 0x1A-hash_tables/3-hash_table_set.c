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
 * Description: a function that adds an elements to the hash table.
 * In case of collision, add the new node at the beginning of the list
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


	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		new_node->next = head;
		head = new_node;
	}

	return (1);
}

/**
 * create_node - function creates a new node of a hash_node_t linked list
 * @key: the value for hash_node_t key member
 * @value: the value for hash_node_t value member
 *
 * Return: the address of the new node or NULL if it fails
 */
hash_node_t *create_node(const char *key, const char *value)
{
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
