class Solution {
public:
    string finalString(string s) {
        string ans;
        for (char c : s) {
            if (c == 'i') {
                for (int i = 0; i < ans.size() / 2; ++i) {
                    swap(ans[i], ans[ans.size() - i - 1]);
                }
            } else {
                ans += c;
            }
        }
        return ans;
    }
};
