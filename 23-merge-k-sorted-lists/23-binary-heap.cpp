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

template <class T, class Container = vector<T>, class Compare = less<typename Container::value_type>>
class BinaryHeap {
public:
    typedef typename Container::const_reference const_reference;

    void push(const T& v) {
        heap.push_back(v);
        int p = heap.size() - 1;
        int parent = (int)floor((p - 1) / 2);
        while (p > parent && comp(heap[parent], heap[p])) {
            T tmp = heap[parent];
            heap[parent] = heap[p];
            heap[p] = tmp;
            p = parent;
            parent = (int)floor((p - 1) / 2);
            if (p < 0 || parent < 0)
                break;
        }
    }

    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        int p = 0;
        int left = p * 2 + 1;
        int right = p * 2 + 2;
        while (left < heap.size()) {
            // if (right >= heap.size())
            //     if (!comp(heap[p], heap[left]))
            //         return;

            if (!comp(heap[p], heap[left]) && !comp(heap[p], heap[right]))
                return;

            if (comp(heap[left], heap[right])) {
                T tmp = heap[right];
                heap[right] = heap[p];
                heap[p] = tmp;
                p = right;
            } else {
                T tmp = heap[left];
                heap[left] = heap[p];
                heap[p] = tmp;
                p = left;
            }
            left = p * 2 + 1;
            right = p * 2 + 2;
        }
    }

    const_reference top() const {
        cout << heap.front()->val << ",";
        return heap.front();
    }

    bool empty() const {
        return heap.empty();
    }

protected:
    Container heap;
    Compare comp;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        //priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        BinaryHeap<ListNode*, vector<ListNode*>, cmp> q;

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
