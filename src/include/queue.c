#include <stdlib.h>
#include "queue.h"

#define GROWTHRATE 1.6

bool less(int *a, int *b){
    return *a < *b;
}
bool greater(int *a, int *b){
    return *a > *b;
}

Heap *init(bool (*compare)(value_type *, value_type *)){
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (heap){
        heap->compare = compare;
        heap->capacity = 10;
        heap->size = 0;
        heap->arr = (value_type *)calloc(heap->capacity, sizeof(value_type));
    }
    return heap;
}
bool empty(Heap *heap){
    return heap->size > 0;
}

size_t size(Heap *heap){
    return heap->size;
}

value_type top(Heap *heap){
    return heap->arr[0];
}
void push(Heap *heap, value_type item){
    if (heap->size == heap->capacity){
        heap->capacity *= GROWTHRATE;
        heap->arr = (value_type *)realloc(heap->arr, heap->capacity * sizeof(value_type));
    }

    int pos = heap->size;
    if (pos == 0) {
		(heap->arr)[0] = item;
		++(heap->size);
		return;
	}
    for (; heap->compare(heap->arr + (pos - 1) / 2, &item) && pos != 0; pos = (pos - 1) / 2){
        (heap->arr)[pos] = (heap->arr)[(pos - 1) / 2];
    }
    (heap->arr)[pos] = item;
    ++(heap->size);
}

void pop(Heap *heap){
    if (heap->size < 1) return;
    value_type *arr = heap->arr;
    int i = 0;
    arr[i] = arr[--(heap->size)];
    while (i * 2 + 1 < heap->size){
        if (heap->compare(arr + i, arr + i * 2 + 1) || heap->compare(arr + i, arr + i * 2 + 2)){
            int chld = (i*2+2 == heap->size) ? (chld = i*2+1) : (heap->compare(arr + i*2+1, arr + i*2+2) ? i*2+2 : i*2+1);
            swap(arr[i], arr[chld]);
            i = chld;
        }else break;
    }
}

static int test()
{
    int a[] = {16, 4, 23, 9, 24, 21, 30, 28, 3, 2, 27, 22, 11, 26, 13, 5, 7, 19, 14, 29, 1, 12, 18, 20, 15, 10, 6, 25, 17, 8};
    
    Heap *heap = init(less);
    if(heap == NULL) return -1;
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) push(heap, a[i]);
    showheap(heap);
    while (heap->size > 0){
        printf("top:%d   ", top(heap));
        pop(heap);
        showheap(heap);
    }
    free(heap->arr);
    return 0;
}

/*
int main(){
    test();
    return 0;
}
*/