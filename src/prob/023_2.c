
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #define value_type int
typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;
typedef ListNode* value_type;

typedef struct Heap
{
    value_type *arr;
    size_t size;
    size_t capacity;
    bool (*compare)(value_type*,value_type*);
}Heap;

#define showheap(heap) {for (int i = 0; i < heap->size; ++i) printf("%d ", (heap->arr)[i]); printf("\n");}
#define swap(a, b)  {  value_type _tmp = a;  a = b, b = _tmp; }




/*
class Solution{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists){
        priority_queue<ListNode *, vector<ListNode *>, cmp> queue;
        for (auto head : lists)
            if (head) queue.push(head);

        ListNode *tmp = new ListNode(0), *tail = tmp;
        while (queue.size()){
            tail->next = queue.top();
            tail = tail->next;
            queue.pop();
            if (tail->next)
                queue.push(tail->next);
        }
        tail = tmp->next;
        delete tmp;
        return tail;
    }
};
*/
#define GROWTHRATE 1.6

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


/*
class Solution{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists){
        priority_queue<ListNode *, vector<ListNode *>, cmp> queue;
        for (auto head : lists)
            if (head) queue.push(head);

        ListNode *tmp = new ListNode(0), *tail = tmp;
        while (queue.size()){
            tail->next = queue.top();
            tail = tail->next;
            queue.pop();
            if (tail->next)
                queue.push(tail->next);
        }
        tail = tmp->next;
        delete tmp;
        return tail;
    }
};
*/
bool cmp(ListNode ** a, ListNode ** b){
        return (*a)->val > (*b)->val;
}
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize){
    Heap*heap = init(cmp);
    for(int i = 0; i<listsSize; ++i){
        if(lists[i])push(heap, lists[i]);
    }
    ListNode *tmp = (ListNode*)calloc(1,sizeof(ListNode)),
             *tail = tmp;
    while(heap->size){
        tail->next = top(heap);
        tail = tail->next;
        pop(heap);
        if(tail->next)
            push(heap, tail->next);
    } 
    tail = tmp->next;
    free(tmp);
    return tail;
}

int main(){

    printf("123");
    return 0;
}