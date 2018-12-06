/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs(struct ListNode *head)
{
    if ((head == NULL) || (head->next == NULL))
        return head;
    show(head);
    struct ListNode *i = head,
                    *j = head->next,
                    *h = NULL,
                    *crthead = head->next;
    while (1)
    {
        i->next = j->next;
        j->next = i;
        if (h)
            h->next = j;
        h = i;
        if (i->next == NULL)
            return crthead ? crthead : head;
        i = i->next;
        if (i->next == NULL)
            return crthead ? crthead : head;
        j = i->next;
    }
    return NULL;
}
