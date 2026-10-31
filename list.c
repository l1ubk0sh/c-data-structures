#include "list.h"
#include <stdlib.h>

void list_init(List* l) {
    l->head = NULL;
    l->size = 0;
}

int list_push_front(List* l, int value) {
    Node* n = malloc(sizeof * n);
    if (!n) return -1;
    n->value = value;
    n->next = l->head;
    l->head = n;
    l->size++;
    return 0;
}

int list_push_back(List* l, int value) {
    Node* n = malloc(sizeof * n);
    if (!n) return -1;
    n->value = value;
    n->next = NULL;
    if (!l->head) {
        l->head = n;
    }
    else {
        Node* cur = l->head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    l->size++;
    return 0;
}

int list_pop_front(List* l, int* out) {
    if (!l->head) return -1;
    Node* n = l->head;
    if (out) *out = n->value;
    l->head = n->next;
    free(n);
    l->size--;
    return 0;
}

Node* list_find(const List* l, int value) {
    for (Node* cur = l->head; cur; cur = cur->next)
        if (cur->value == value) return cur;
    return NULL;
}

void list_reverse(List* l) {
    Node* prev = NULL, * cur = l->head;
    while (cur) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    l->head = prev;
}

void list_free(List* l) {
    Node* cur = l->head;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    l->head = NULL;
    l->size = 0;
}