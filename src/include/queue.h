#include <stdbool.h>
#include <stdio.h>
// #define value_type int
typedef int value_type;

typedef struct Heap
{
    value_type *arr;
    size_t size;
    size_t capacity;
    bool (*compare)(value_type*,value_type*);
}Heap;

#define showheap(heap) {for (int i = 0; i < heap->size; ++i) printf("%d ", (heap->arr)[i]); printf("\n");}
#define swap(a, b)  {  value_type _tmp = a;  a = b, b = _tmp; }

bool less(value_type *a, value_type *b);
bool greater(value_type *a, value_type *b);

Heap* init();
bool empty(Heap*);
size_t size(Heap*);
value_type top(Heap*);
void push(Heap*,value_type);
void pop(Heap*);
