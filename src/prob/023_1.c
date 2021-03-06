/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2);
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize){
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];
    struct ListNode *l1 = mergeKLists(lists,  listsSize / 2),
                    *l2 = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);
    return mergeTwoLists(l1, l2);
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct ListNode *crt, *res;
    if (l1->val < l2->val){
        crt = l1;
        l1 = l1->next;
    }else{
        crt = l2;
        l2 = l2->next;
    }
    res = crt;

    while (l1 && l2){
        if (l1->val < l2->val){
            crt->next = l1;
            l1 = l1->next;
        }else{
            crt->next = l2;
            l2 = l2->next;
        }
        crt = crt->next;
    }
    if (l1 == NULL && l2 == NULL)
        return res;

    crt->next = l1 ? l1 : l2;
    return res;
}
