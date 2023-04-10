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
	hash_table_t *table;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
	{
		return (NULL);
	}

	table->size = size;
	table->array = calloc(table->size, sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	return (table);
}
