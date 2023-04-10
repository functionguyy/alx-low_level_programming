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

	ht_array_idx = key_index((const unsigned char *)key, ht->size);
	head = ht->array[ht_array_idx];

	new_node = add_node(&head, key, value);
	if (new_node == NULL)
		return (0);

	printf("%p", (void *)new_node);

	return (1);
}

/**
 * add_node - function adds a new node t beginning of a hash_node_t linked list
 * @head: pointer to pointer to the last added node
 * @key: the value for hash_node_t key member
 * @value: the value for hash_node_t value member
 *
 * Return: the address of the new node or NULL if it fails
 */
hash_node_t *add_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	if (key)
	{
		new_node->key = strdup(key);
		new_node->value = strdup(value);
	}
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
