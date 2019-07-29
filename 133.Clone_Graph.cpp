#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;

  Node() {}

  Node(int _val) : val(_val) {}
  Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node);
};

Node *Solution::cloneGraph(Node *node) {
    if (!node) return nullptr;

    unordered_map<Node*, Node*> map(128);
    queue<Node*> q;
    q.push(node);
    Node *clone = new Node(node->val);
    map[node] = clone;

    while (!q.empty()) {
        Node *n = q.front();
        q.pop();
        for (Node *neighbor : n->neighbors) {
            if (!map.count(neighbor)) {
                map[neighbor] = new Node(neighbor->val);
                q.push(neighbor);
            }
            map[n]->neighbors.push_back(map[neighbor]);
        }
    }
    return clone;
}

int main() {
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);

    one->neighbors = vector<Node*>();
    one->neighbors.push_back(two);
    one->neighbors.push_back(four);

    two->neighbors = vector<Node*>();
    two->neighbors.push_back(one);
    two->neighbors.push_back(three);

    three->neighbors = vector<Node*>();
    three->neighbors.push_back(two);
    three->neighbors.push_back(four);

    four->neighbors = vector<Node*>();
    four->neighbors.push_back(one);
    four->neighbors.push_back(three);

    Solution s;
    Node *clone = s.cloneGraph(one);
    return 0;
}
