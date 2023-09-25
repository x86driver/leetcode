class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> m1(26);
        vector<int> m2(26);
        for (char c : s)
            ++m1[c - 'a'];
        for (char c : t)
            ++m2[c - 'a'];
        for (int i = 0; i < 26; ++i) {
            if (m1[i] != m2[i])
                return i + 'a';
        }
        return s[0];
    }
};

