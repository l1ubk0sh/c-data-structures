#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    size_t size;
} List;

void  list_init(List* l);
int   list_push_front(List* l, int value);   /* 0 = ok, -1 = alloc failed */
int   list_push_back(List* l, int value);
int   list_pop_front(List* l, int* out);     /* 0 = ok, -1 = empty */
Node* list_find(const List* l, int value);
void  list_reverse(List* l);
void  list_free(List* l);

#endif