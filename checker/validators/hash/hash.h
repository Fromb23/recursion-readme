#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>
#include "registry_hash.h"

typedef struct HashEntry {
	const char *key;
	ValidatorFn value;
	struct HashEntry *next;
} HashEntry;

typedef struct HashTable {
	size_t size;
	HashEntry **buckets;
} HashTable;

HashTable *create_table(size_t size);
void insert(HashTable *table, const char *key, ValidatorFn value);
ValidatorFn get(HashTable *table, const char *key);
void free_table(HashTable *table);

#endif
