#include <string.h>
#include <stdlib.h>
#include "kv.h"

#define RET_SUCCESS 0
#define RET_EINPUT -1
#define RET_EINTERN -2

kv_t*kv_init(size_t capacity) {
	if (capacity == (long long) NULL) return NULL;

	kv_t*table = malloc(sizeof(kv_t));
	if (table == NULL) return NULL;

	table->capacity = capacity;
	table->count = 0;
	table->entries = calloc(sizeof(kv_entry_t), capacity);

	if (table->entries == NULL) return NULL;

	return table;
}

size_t kv_hash(char*val, int capacity) {
	size_t hashish = 0x1337dead1337beef;

	while (*val) {
		hashish ^= *val;
		hashish <<= 8;
		hashish += *val;

		val++;
	}

	return hashish % capacity;
}
/*
int kv_put(kv_t*table, char*key, char*value) {
	if (!table || !key || !value) return -1;

	size_t idx = kv_hash(key, table->capacity);

	size_t first_tombstone;

	char tombstone_found = 0;

	for (int i = 0; i < table->capacity; i++) {

		size_t real_idx = (idx + i) % table->capacity;
		
		kv_entry_t*e = &table->entries[real_idx];

		//key exists, updating
		if (e->key && !strcmp(e->key, key)) {
			char*newval = strdup(value);
			if (!newval) return RET_EINPUT;
			e->value = newval;
			return real_idx;
		}

		//empty slot (null or tombstone)
		if (!e->key || e->key == (void*) TOMBSTONE) {
			char*newkey = strdup(key);
			char*newval = strdup(value);
			if (!newval||!newkey) {
				free(newval);
				free(newkey);
				return RET_EINPUT;
			}
			e->key = newkey;
			e->value = newval;
			table->count++;
			return real_idx;
		}

		if (!tombstone_found && e->key != (void*) TOMBSTONE) {
			tombstone_found = 1;
			first_tombstone = real_idx;
		}
	}

	if (tombstone_found) {
		char*newkey = strdup(key);
		char*newval = strdup(value);
		if (!newval||!newkey) {
			free(newval);
			free(newkey);
			return RET_EINPUT;
		}
		table->entries[first_tombstone].key = newkey;
		table->entries[first_tombstone].value = newval;
		table->count++;
		return first_tombstone;
	}

	return RET_EINTERN;
}
*/
void kv_free(kv_t*table) {
	free(table->entries);
	free(table);
}
