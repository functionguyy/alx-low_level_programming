#include <stddef.h>
#include <stdlib.h>
#include "hash_tables.h"
/**
 * hash_table_create - A function that creates a hashtable
 * @size: the size of the array
 *
 * Description: Write a function that creates a hash table.
 * Return: a pointer to the newly created hash table or NULL if error
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	/* declare variables */
	hash_table_t *table;
	unsigned long int arr_idx;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	/**
	 * calloc used to allocate virtual space for very large
	 * memory allocation request
	 */
	table->array = calloc(table->size, sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	/**
	 * initialize each cell in the table array to be the head of an empty
	 * hash_node_t singly linked list
	 */
	for (arr_idx = 0; arr_idx < table->size; arr_idx++)
		table->array[arr_idx] = NULL;

	return (table);
}
