#include "dynarray.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 4

void da_init(DynArray* a) {
    a->data = NULL;
    a->size = 0;
    a->capacity = 0;
}

int da_push(DynArray* a, int value) {
    if (a->size == a->capacity) {
        size_t new_cap = (a->capacity == 0) ? INITIAL_CAPACITY : a->capacity * 2;
        int* tmp = realloc(a->data, new_cap * sizeof * tmp);
        if (!tmp) return -1;
        a->data = tmp;
        a->capacity = new_cap;
    }
    a->data[a->size++] = value;
    return 0;
}

int da_pop(DynArray* a, int* out) {
    if (a->size == 0) return -1;
    a->size--;
    if (out) *out = a->data[a->size];
    return 0;
}

int da_get(const DynArray* a, size_t index, int* out) {
    if (index >= a->size) return -1;
    *out = a->data[index];
    return 0;
}

void da_free(DynArray* a) {
    free(a->data);
    a->data = NULL;
    a->size = 0;
    a->capacity = 0;
}