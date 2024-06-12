/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        vector<ImmutableListNode*> listArray(1001);
        int count = 0;
        while (head) {
            listArray[count++] = head;
            head = head->getNext();
        }
        for (int i = count - 1; i >= 0; --i)
            listArray[i]->printValue();
    }
};
