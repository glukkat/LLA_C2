#include <assert.h>
#include <stdio.h>

#include "kv.h"

int main() {
	kv_t *db = kv_init(16);
	kv_put(db, "Hi", "Hello");
	for (int i = 0; i < db->capacity; i++) {
		if (db->entries[i].key) printf("%d - %s: %s\n", i, db->entries[i].key, db->entries[i].value);
	}
}
