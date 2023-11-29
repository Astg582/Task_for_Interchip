
#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct {
    int* arr;
    size_t size;
    size_t cap;
} Vint;

Vint construct_0();
Vint construct_s(size_t size);
Vint construct_v(size_t size, int val);
void Deletion(Vint* ob);
void resize(Vint* ob, size_t new_size);
void recap(Vint* ob);
void push_back(Vint* ob, int val);
void Insert(Vint* ob, size_t index, int value);
bool empty(Vint* ob);
int Access(Vint* ob, size_t index);
void Sort(Vint* ob);

#endif // VECTOR_H
