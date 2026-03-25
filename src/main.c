#include <assert.h>

#include "kv.h"

int main() {
	kv_t *db = kv_init(16);
	kv_put(db, "Hi", "Hello");
}
