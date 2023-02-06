class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int i = 0;
        int j = 0;
        int maximum = 0;

        while (j < s.size()) {
            ++m[s[j]];
            if (m.size() > 2) {
                maximum = max(maximum, j - i);
                while (i < j && m.size() > 2) {
                    --m[s[i]];
                    if (m[s[i]] == 0)
                        m.erase(s[i]);
                    ++i;
                }
            }
            ++j;
        }

        return max(maximum, j - i);
    }
};
