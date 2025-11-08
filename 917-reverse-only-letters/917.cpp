class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = s.size() - 1;
        string ans;
        while (start < s.size() && end >= 0) {
            if (isalpha(s[start]) && isalpha(s[end])) {
                ans += s[end];
                ++start;
                --end;
            } else {
                if (!isalpha(s[start])) {
                    ans += s[start];
                    ++start;
                } else if (!isalpha(s[end])) {
                    --end;
                }
            }
        }
        while (start < s.size()) {
            ans += s[start];
            ++start;
        }
        return ans;
    }
};
