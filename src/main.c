#include <assert.h>
#include <stdio.h>

#include "kv.h"

int main() {
	kv_t *db = kv_init(16);
	kv_put(db, "0", "0");
	kv_put(db, "1", "1");
	kv_put(db, "2", "2");
	kv_put(db, "3", "3");
	kv_put(db, "4", "4");
	kv_put(db, "5", "5");
	kv_put(db, "6", "6");
	kv_put(db, "7", "7");
	kv_put(db, "8", "8");
	kv_put(db, "9", "9");
	kv_put(db, "a", "a");
	kv_put(db, "b", "b");
	kv_put(db, "c", "c");
	kv_put(db, "d", "d");
	kv_put(db, "e", "e");
	kv_put(db, "f", "f");
	for (int i = 0; i < db->capacity; i++) {
		if (db->entries[i].key) printf("%d - %s: %s\n", i, db->entries[i].key, db->entries[i].value);
	}
}
