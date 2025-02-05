class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        set<char> set1, set2;
        int count = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                set1.insert(s1[i]);
                set2.insert(s2[i]);
                ++count;
            }
        }
        if (count != 0 && count != 2) {
            return false;
        }
        return set1 == set2;
    }
};
