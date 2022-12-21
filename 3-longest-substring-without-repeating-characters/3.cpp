class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1) {
            return s.size();
        }

        int length = 0;
        int left = 0;
        int right = 1;
        unordered_map<char, int> m;

        m[s[0]] = 0;
        while (right < s.size()) {
            if (m.find(s[right]) == m.end()) {
                length = std::max(length, right-left+1);
            } else {
                length = std::max(length, right-left);
                for (int i = left; i < m[s[right]]; ++i) {
                    if (m[s[i]] <= i) {
                        m.erase(s[i]);
                    }
                }
                left = m[s[right]] + 1;
            }
            m[s[right]] = right;
            ++right;
        }

        return length;
    }
};
