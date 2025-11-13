class Solution {
public:
    int removePalindromeSub(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] == s[end]) {
                ++start;
                --end;
                continue;
            } else {
                return 2;
            }
        }
        return 1;
    }
};
