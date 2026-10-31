#include "dynarray.h"
#include <assert.h>
#include <stdio.h>

void test_dynarray(void) {
    DynArray a;
    da_init(&a);
    assert(a.size == 0 && a.capacity == 0);

    for (int i = 0; i < 10; i++)
        assert(da_push(&a, i * 10) == 0);
    assert(a.size == 10);
    assert(a.capacity == 16);   /* 4 -> 8 -> 16 */

    int v;
    assert(da_get(&a, 3, &v) == 0 && v == 30);
    assert(da_get(&a, 10, &v) == -1);

    assert(da_pop(&a, &v) == 0 && v == 90);
    assert(a.size == 9);

    da_free(&a);
    assert(a.data == NULL && a.size == 0);
    assert(da_pop(&a, &v) == -1);

    puts("dynarray tests passed");
}