class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;
        for (char c : s) {
            if (depth == 0 && c == '(') {
                ++depth;
                continue;
            }
            if (c == '(') {
                ++depth;
            } else {
                --depth;
                if (depth == 0) {
                    continue;
                }
            }
            ans += c;
        }
        return ans;
    }
};
