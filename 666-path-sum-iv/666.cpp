class Solution {
private:
    int ans;
    void extract(int num, int *depth, int *position, int *val) {
        *val = num % 10;
        num /= 10;
        *position = num % 10;
        num /= 10;
        *depth = num;
    }
    void dfs(TreeNode* node, int pathSum) {
        if (!node)
            return;
        pathSum += node->val;
        if (!node->left && !node->right) {
            ans += pathSum;
            return;
        }
        dfs(node->left, pathSum);
        dfs(node->right, pathSum);
    }
public:
    int pathSum(vector<int>& nums) {
        ans = 0;
        vector<vector<int>> tree = {
            vector<int>(1, -1),
            vector<int>(2, -1),
            vector<int>(4, -1),
            vector<int>(8, -1)
        };
        for (int num : nums) {
            int depth = 0, position = 0, val = 0;
            extract(num, &depth, &position, &val);
            tree[depth - 1][position - 1] = val;
        }

        TreeNode* root = new TreeNode(tree[0][0]);
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) {
                    q.push(nullptr);
                    q.push(nullptr);
                    continue;
                }
                if (tree[level + 1][i * 2] != -1) {
                    node->left = new TreeNode(tree[level + 1][i * 2]);
                }
                q.push(node->left);
                if (tree[level + 1][i * 2 + 1] != -1) {
                    node->right = new TreeNode(tree[level + 1][i * 2 + 1]);
                }
                q.push(node->right);
            }

            ++level;
            if (level >= 3)
                break;
        }

        dfs(root, 0);
        return ans;
    }
};
