#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct ListNode *append(struct ListNode *tail, int val)
{
    struct ListNode *newTail = (struct ListNode *)malloc(sizeof(struct ListNode *));
    newTail->val = val;
    tail->next = newTail;
    return newTail;
}

struct ListNode *init(int *A, int ASize)
{
    // if(ASize>1)
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode *)), *tail = head;
    tail->val = A[0];
    for (int i = 1; i < ASize; ++i){
        tail = append(tail, A[i]);
    }
    tail->next = NULL;
    return head;
}

void showNEnd(const char *s, struct ListNode *head, struct ListNode *tail)
{
    printf("%s :\t", s);
    if (head == NULL)
        printf("NULL");
    else{
        while (head != tail){
            printf("%d-> ", head->val);
            head = head->next;
        }
        printf("%d", head->val);
    }
    printf("\n");
}

void show(const char *s, struct ListNode *head)
{
        printf("%s :\t", s);
    if (head == NULL)
        printf("NULL");
    else{
        while (head->next != NULL){
            printf("%d-> ", head->val);
            head = head->next;
        }
        printf("%d", head->val);
    }
    printf("\n");
}


struct ListNode *getEnd(struct ListNode *list)
{
    while (list->next != NULL)
        list = list->next;
    return list;
}

/*
 * [begin1, end1]
 * [begin2, end2]
 * mend is for getting the real ptr of the merged-list's tail 
 * return the ptr of the merged-list 
 */
struct ListNode* merge(
    struct ListNode *begin1,
    struct ListNode *end1,
    struct ListNode *begin2,
    struct ListNode *end2,
    struct ListNode **mend)
{
    struct ListNode *mbegin, *cend;
    if (begin1 == end1 && begin2 == end2){
        if (begin1->val < begin2->val){
            *mend = begin2;
            mbegin = begin1;
        }
        else{
            *mend = begin1;
            mbegin = begin2;
        }
        mbegin->next = *mend;
        (*mend)->next = NULL;
        return mbegin;
    }
    else if (begin1 == end1)
        return merge(begin2, end2, begin1, end1, mend);

    if (begin1->val < begin2->val){
        mbegin = begin1;
        begin1=begin1->next;
    }
    else{
        mbegin = begin2;
        begin2= begin2->next;
    }
    cend = mbegin;
    while (begin1 != end1->next && begin2 != end2->next){
        if (begin1->val < begin2->val){
            cend->next = begin1;
            cend = begin1;
            begin1 = begin1->next;
        }
        else{
            cend->next = begin2;
            cend = begin2;
            begin2 = begin2->next;
        }
    }
    if(begin1 == end1->next || begin2 == end2->next){
        struct ListNode *begin,
                        *end;
        if(begin1 == end1->next){
            begin = begin2;
            end = end2;
        }
        else{
            begin = begin1;
            end = end1;
        }
        while(begin != end->next){
            cend->next = begin;
            cend = begin;
            begin = begin->next;
        }
    }
    cend->next = NULL;
    *mend = cend;
    return mbegin;
}

struct ListNode* mergesort_list(
    struct ListNode *begin,
    struct ListNode *end,
    struct ListNode **sortedTail)
{
    printf("from:%d to:%d\t ", begin->val, end->val);

    showNEnd("|",begin,end);
    if (begin == end)
    {
        *sortedTail = begin;
        return begin;
    }

    struct ListNode *p, *q;
    // list = [begin, p] + [p.next, q] = [begin, end]
    p = begin;
    q = begin->next;
    while (q!= end)
    {
        p = p->next;
        q = q->next;
        if (q!= end)
            q = q->next;
    }
    printf("p:%d q:%d\n\n", p->val, q->val);

    struct ListNode *tail1 = NULL,
                    *tail2 = NULL,
                    *list1 = mergesort_list(begin, p, &tail1),
                    *list2 = mergesort_list(p->next, end, &tail2),
                    *mtail = NULL,
                    *sortedList = merge(list1, tail1, list2, tail2, &mtail);
    printf("combined!\n");
    //printf("%d %d %d %d\n",list1->val, begin->val, p->val, tail1->val);
    //printf("%d %d %d %d\n",list2->val, p->next->val, end->val, tail2->val);
    *sortedTail = mtail;
    return sortedList;


    //return NULL;
}


int main()
{
    int arr1[] = {1},
        arr2[] = {2,1},
        arr[] = {3,1,5,8,6,2,7,0,9,4};
    struct ListNode *list1 = init(arr1, 1),
                    *list2 = init(arr2, 2),
                    *list = init(arr, 10),
                    *res,
                    *tail;
    // show("list1", list1);
    // show("res",merge(list1,getEnd(list1),list2,getEnd(list2),&tail));
    //show("list2", list2);
    
    
    // show("list", list);
    res = mergesort_list(list2, getEnd(list2), &tail);
    show("res",res);
    //printf("%p %d",res, res->val);
    return 0;
}
