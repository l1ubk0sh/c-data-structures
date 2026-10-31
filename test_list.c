#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_list(void) {
    List l;
    list_init(&l);

    assert(list_push_back(&l, 1) == 0);
    assert(list_push_back(&l, 2) == 0);
    assert(list_push_front(&l, 0) == 0);
    assert(l.size == 3);

    assert(list_find(&l, 2) != NULL);
    assert(list_find(&l, 99) == NULL);

    list_reverse(&l);
    assert(l.head->value == 2);

    int v;
    assert(list_pop_front(&l, &v) == 0 && v == 2);
    assert(l.size == 2);

    list_free(&l);
    assert(l.size == 0 && l.head == NULL);
    assert(list_pop_front(&l, &v) == -1);

    puts("list tests passed");;
   
}