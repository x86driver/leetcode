class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        if (s.size() < 3)
            return 0;
        for (size_t i = 0; i < s.size() - 2; ++i) {
            cout << s[i] << s[i+1] << s[i+2] << endl;
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2])
                ++count;
        }
        return count;
    }
};
