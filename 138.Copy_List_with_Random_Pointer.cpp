#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node() {}

  Node(int _val) : val(_val), next(nullptr), random(nullptr) {}

  Node(int _val, Node* _next, Node* _random) {
      val = _val;
      next = _next;
      random = _random;
  }
};

class Solution {
public:
  unordered_map<Node*, Node*> map;
  unordered_set<Node*> set;

  Solution() : map(128), set(128) {}

  Node *cloneNode(Node *node) {
      if (!node) return nullptr;
      if (set.count(node)) {
          return map[node];
      }
      Node *clone = new Node(node->val, nullptr, nullptr);
      map[node] = clone;
      set.insert(node);
      return clone;
  }

  Node* copyRandomList(Node* head) {
      if (!head) return nullptr;

      Node *root = cloneNode(head);
      Node *cur = head;
      Node *node = root;
      while (cur) {
          node->next = cloneNode(cur->next);
          node->random = cloneNode(cur->random);
          node = node->next;
          cur = cur->next;
      }
      return root;
  }
};

int main() {
    Node *one = new Node(1);
    Node *two = new Node(2);

    one->next = two;
    one->random = two;

    two->random = two;

    Solution s;
    Node *clone = s.copyRandomList(one);
    return 0;
}
