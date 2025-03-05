#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>

struct stable {
    size_t size;
};

struct stable *STnew(size_t size) {
    struct stable *table = malloc(sizeof(struct stable)); 
    if (table == NULL) {
        return NULL;
    }
    table->size = size;
    return table;
}