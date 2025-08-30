class Solution {
public:
    int maxPower(string s) {
        int maxLen = 1;
        int len = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++len;
            } else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        return max(maxLen, len);
    }
};
