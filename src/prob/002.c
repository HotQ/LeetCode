struct ListNode
{
    int val;
    struct ListNode *next;
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    // cf: Carry Flag
    int cf = 0,
        i = 0;

    struct ListNode *list = (struct ListNode *)malloc(sizeof(struct ListNode)),
                    *tail = list,
                    *longerList = NULL;
    i = (l1->val) + (l2->val);
    cf = (i >= 10);
    tail->val = i % 10;
    tail->next = NULL;

    l1 = l1->next;
    l2 = l2->next;

    while (l1 && l2)
    {
        i = (l1->val) + (l2->val) + cf;
        cf = (i >= 10);
        tail->next = (struct ListNode *)malloc(sizeof(struct ListNode)),
        tail = tail->next;
        tail->next = NULL;
        tail->val = i % 10;

        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 || l2)
    {
        longerList = l1 ? l1 : l2;

        while (longerList)
        {
            i = (longerList->val) + cf;
            cf = (i >= 10);
            tail->next = (struct ListNode *)malloc(sizeof(struct ListNode)),
            tail = tail->next;
            tail->next = NULL;
            tail->val = i % 10;

            longerList = longerList->next;
        }
    }
    if (cf)
    {
        tail->next = (struct ListNode *)malloc(sizeof(struct ListNode)),
        tail->next->next = NULL;
        tail->next->val = 1;
    }
    return list;
}
