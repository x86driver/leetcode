#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include "../lib/tree.h"

using namespace std;

TreeNode* stringToTreeNode(string input);

class Solution {
public:
  Solution() : count(0) {}
  void preorder_traversal(struct TreeNode *root) {
      if (root) {
          ++count;
          preorder_traversal(root->left);
          preorder_traversal(root->right);
      }
  }

  int countNodes(struct TreeNode *root) {
      count = 0;
      preorder_traversal(root);
      return count;
  }
private:
  int count;
};

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        print_ascii_tree(root);

        int ret = Solution().countNodes(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
