struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *append(struct ListNode *tail, int val);
struct ListNode *init(int *A, int ASize);
void show(const char *s, struct ListNode *head);
void showNEnd(const char *s, struct ListNode *head, struct ListNode *tail);