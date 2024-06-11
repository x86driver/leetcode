class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> m(26);
        for (char c : s)
            m[c - 'a'] = true;
        int count = 0;
        for (int i = 0; i < m.size(); ++i)
            if (m[i])
                ++count;
        return count;
    }
};
