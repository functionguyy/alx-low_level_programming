#include "hash_tables.h"
/**
 * key_index - function that gives you the index of a key
 * @key: the key
 * @size: the size of the array of the hash table
 *
 * Description: This function uses the djb2 algorithm
 * Return: index at which the key/value pair should be stored in the array of
 * the hashtable
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* declare variables */
	unsigned long int hash_code, table_idx;

	/* hash the key */
	hash_code = hash_djb2(key);

	table_idx = hash_code % size;


	return (table_idx);
}
