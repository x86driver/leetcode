class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> m1(26), m2(26);
        for (char c : word1) {
            ++m1[c - 'a'];
        }
        for (char c : word2) {
            ++m2[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (abs(m1[i] - m2[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};
