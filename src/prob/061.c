/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (k == 0) return head;
    struct ListNode *pfast = head,
                    *pslow = head,
                    *count = head;
    int size = 0;
    while (count){ ++size; count = count->next; }
    if (size == 0) return head;
    k = k % size;
    while (k--) pfast = pfast->next;
    while (pfast->next){ pfast = pfast->next; pslow = pslow->next; }
    pfast->next = head;
    head = pslow->next;
    pslow->next = NULL;
    return head;
}
