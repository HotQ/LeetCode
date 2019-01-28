#include <stdbool.h>

// #define value_type int
typedef int value_type;

typedef struct Heap
{
    value_type *arr;
    size_t size;
    size_t capacity;
    bool (*compare)(value_type*,value_type*);
}Heap;

bool less(value_type *a, value_type *b);
bool greater(value_type *a, value_type *b);

Heap* init();
bool empty(Heap*);
bool size(Heap*);
value_type top(Heap*);
void push(Heap*,value_type);
void pop(Heap*);
