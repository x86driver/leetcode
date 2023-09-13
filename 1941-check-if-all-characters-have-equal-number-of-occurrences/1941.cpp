class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> m(26);
        for (char c : s)
            ++m[c - 'a'];
        int std = m[s[0] - 'a'];
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] && m[i] != std)
                return false;
        }
        return true;
    }
};
