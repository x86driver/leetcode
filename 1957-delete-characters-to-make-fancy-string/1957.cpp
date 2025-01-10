class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) {
            return s;
        }
        string ans = s.substr(0, 2);
        int ansIndex = 1;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == ans[ansIndex] && s[i] == ans[ansIndex - 1]) {
                continue;
            }
            ans += s[i];
            ++ansIndex;
        }
        return ans;
    }
};
