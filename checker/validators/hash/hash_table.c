#include <stdlib.h>
#include <string.h>
#include "hash.h"

static unsigned long hash(const char *str)
{
	unsigned long hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash;
}

HashTable *create_table(size_t size)
{
	HashTable *table;
	size_t i;

	table = malloc(sizeof(HashTable));
	if (!table)
		return NULL;

	table->buckets = malloc(sizeof(HashEntry *) * size);
	if (!table->buckets) {
		free(table);
		return NULL;
	}

	table->size = size;
	for (i = 0; i < size; i++)
		table->buckets[i] = NULL;

	return table;
}

void insert(HashTable *table, const char *key, ValidatorFn value)
{
	unsigned long index;
	HashEntry *entry;
	HashEntry *new_entry;

	if (!table || !key)
		return;

	index = hash(key) % table->size;
	entry = table->buckets[index];

	while (entry != NULL) {
		if (strcmp(entry->key, key) == 0) {
			entry->value = value;
			return;
		}
		entry = entry->next;
	}

	new_entry = malloc(sizeof(HashEntry));
	if (!new_entry)
		return;

	new_entry->key = key;
	new_entry->value = value;
	new_entry->next = table->buckets[index];
	table->buckets[index] = new_entry;
}

ValidatorFn get(HashTable *table, const char *key)
{
	unsigned long index;
	HashEntry *entry;

	if (!table || !key)
		return NULL;

	index = hash(key) % table->size;
	entry = table->buckets[index];

	while (entry != NULL) {
		if (strcmp(entry->key, key) == 0)
			return entry->value;
		entry = entry->next;
	}

	return NULL;
}

void free_table(HashTable *table)
{
	size_t i;
	HashEntry *entry;
	HashEntry *temp;

	if (!table)
		return;

	for (i = 0; i < table->size; i++) {
		entry = table->buckets[i];
		while (entry != NULL) {
			temp = entry;
			entry = entry->next;
			free(temp);
		}
	}

	free(table->buckets);
	free(table);
}
