class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), 1e4 + 1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                for (int j = i; j >= 0; --j) {
                    if (ans[j] < i - j)
                        break;
                    ans[j] =  i - j;
                }
                int j;
                for (j = i + 1; j < s.size() && s[j] != c; ++j)
                    ans[j] = j - i;
                i = j - 1;
            }
        }
        return ans;
    }
};
