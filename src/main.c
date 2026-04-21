#include <assert.h>
#include <stdio.h>

#include "kv.h"

int main() {
	kv_t *db = kv_init(16);
	printf("%d\t", kv_put(db, "0", "0"));
	printf("%d\t", kv_put(db, "1", "1"));
	printf("%d\t", kv_put(db, "2", "2"));
	printf("%d\t", kv_put(db, "3", "3"));
	printf("%d\t", kv_put(db, "4", "4"));
	printf("%d\t", kv_put(db, "5", "5"));
	printf("%d\t", kv_put(db, "6", "6"));
	printf("%d\t", kv_put(db, "7", "7"));
	printf("%d\t", kv_put(db, "8", "8"));
	printf("%d\t", kv_put(db, "9", "9"));
	printf("%d\t", kv_put(db, "a", "a"));
	printf("%d\t", kv_put(db, "b", "b"));
	printf("%d\t", kv_put(db, "c", "c"));
	printf("%d\t", kv_put(db, "d", "d"));
	printf("%d\t", kv_put(db, "e", "e"));
	printf("%d\n", kv_put(db, "f", "f"));
	puts("");

	for (int i = 0; i < db->capacity; i++) {
		if (db->entries[i].key) printf("%d - %s: %s\n", i, db->entries[i].key, db->entries[i].value);
	}
	puts("\n");

	kv_put(db, "7", "NEIN!!!");
	kv_delete(db, "c");
	kv_put(db, "C", "CCCP!!!!");

	for (int i = 0; i < db->capacity; i++) {
		if (db->entries[i].key) printf("%d - %s: %s\n", i, db->entries[i].key, db->entries[i].value);
	}

	kv_free(db);
}
