class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        string ans;
        for (char c : s) {
            if (m[c] == c - '0') {
                if (ans.size() == 0) {
                    ans = c;
                } else if (ans.size() == 1 && ans[0] != c) {
                    ans += c;
                    break;
                }
            } else {
                ans = "";
            }
        }
        if (ans.size() == 2) {
            return ans;
        } else {
            return "";
        }
    }
};
