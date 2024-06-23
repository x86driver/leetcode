class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> m(26);
        for (char c : s)
            ++m[c - 'a'];
        int v = 0;
        int i;
        for (i = 0; i < m.size(); ++i) {
            if (m[i] != v) {
                v = m[i];
                break;
            }
        }
        for (; i < m.size(); ++i) {
            if (m[i] != 0 && m[i] != v)
                return false;
        }
        return true;
    }
};
