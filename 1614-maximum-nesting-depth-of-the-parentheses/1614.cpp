class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int level = 0;
        for (char c : s) {
            if (c == '(') {
                ++level;
            } else if (c == ')') {
                ans = max(ans, level);
                --level;
            }
        }
        return ans;
    }
};
