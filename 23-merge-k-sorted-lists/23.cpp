/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct cmp {
    bool operator()(const ListNode* a, const ListNode* b) {
        return b->val < a->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;

        const int k = lists.size();
        for (int i = 0; i < k; ++i) {
            if (lists[i])
                q.push(lists[i]);
        }

        if (q.empty())
            return nullptr;

        ListNode *head = q.top();
        ListNode *node = head;

        q.pop();
        if (node->next)
            q.push(node->next);

        while (!q.empty()) {
            ListNode *top = q.top();
            node->next = top;
            node = node->next;
            q.pop();
            if (top->next)
                q.push(top->next);
        }

        return head;
    }
};
