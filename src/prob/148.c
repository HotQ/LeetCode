#include <stdlib.h>
#include "linkedlist.h"

/*
 * [begin1, end1]
 * [begin2, end2]
 * mend is for getting the real ptr of the merged-list's tail 
 * return the ptr of the merged-list 
 */
struct ListNode *merge(struct ListNode *begin1, struct ListNode *end1, struct ListNode *begin2, struct ListNode *end2, struct ListNode **mend);
struct ListNode *mergesort_list(struct ListNode *begin, struct ListNode *end, struct ListNode **sortedTail);
struct ListNode *getEnd(struct ListNode *list);

struct ListNode *sortList(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    struct ListNode *tail;
    return mergesort_list(head, getEnd(head), &tail);
}

struct ListNode *getEnd(struct ListNode *list)
{
    while (list->next != NULL)
        list = list->next;
    return list;
}
struct ListNode *merge(
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
        }else{
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
        begin1 = begin1->next;
    }else{
        mbegin = begin2;
        begin2 = begin2->next;
    }
    cend = mbegin;
    while (begin1 != end1->next && begin2 != end2->next){
        if (begin1->val < begin2->val){
            cend->next = begin1;
            cend = begin1;
            begin1 = begin1->next;
        }else{
            cend->next = begin2;
            cend = begin2;
            begin2 = begin2->next;
        }
    }
    if (begin1 == end1->next || begin2 == end2->next){
        struct ListNode *begin,
            *end;
        if (begin1 == end1->next){
            begin = begin2;
            end = end2;
        }else{
            begin = begin1;
            end = end1;
        }
        while (begin != end->next){
            cend->next = begin;
            cend = begin;
            begin = begin->next;
        }
    }
    cend->next = NULL;
    *mend = cend;
    return mbegin;
}

struct ListNode *mergesort_list(
    struct ListNode *begin,
    struct ListNode *end,
    struct ListNode **sortedTail)
{

    if (begin == end){
        *sortedTail = begin;
        return begin;
    }

    struct ListNode *p, *q;
    // list = [begin, p] + [p.next, q] = [begin, end]
    p = begin;
    q = begin->next;
    while (q != end){
        p = p->next;
        q = q->next;
        if (q != end)
            q = q->next;
    }
    q = p->next;
    struct ListNode *tail1,
        *tail2,
        *list1 = mergesort_list(begin, p, &tail1),
        *list2 = mergesort_list(q, end, &tail2),
        *mtail,
        *sortedList = merge(list1, tail1, list2, tail2, &mtail);

    *sortedTail = mtail;
    return sortedList;
}
