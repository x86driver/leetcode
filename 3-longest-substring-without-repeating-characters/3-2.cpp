class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int left = 0;
        int right = 1;
        int length = 1;
        set<char> m;
        m.insert(s[0]);
        while (right < s.size()) {
            if (m.find(s[right]) == m.end()) {
                m.insert(s[right]);
                ++right;
                length = max(length, right - left);
                continue;
            }
            for (int i = left; i < right; ++i) {
                m.erase(s[i]);
                if (s[i] == s[right]) {
                    left = i + 1;
                    break;
                }
            }
        }

        return length;
    }
};
