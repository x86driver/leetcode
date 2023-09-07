class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> v(26);
        int count = 0;
        for (char c : s)
            v[c - 'a'] = true;
        for (int i = 0; i < v.size(); ++i)
            count += v[i];
        return count;
    }
};
