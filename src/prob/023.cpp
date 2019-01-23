/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    bool operator()(ListNode *&a, ListNode *&b){
        return a->val > b->val;
    }
};

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
