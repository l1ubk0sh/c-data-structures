#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DynArray;

void da_init(DynArray* a);
int  da_push(DynArray* a, int value);                   /* 0 = ok, -1 = alloc failed */
int  da_pop(DynArray* a, int* out);                     /* 0 = ok, -1 = empty */
int  da_get(const DynArray* a, size_t index, int* out); /* 0 = ok, -1 = out of range */
void da_free(DynArray* a);

#endif