class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26), upper(26);
        for (char c : word) {
            if (islower(c)) {
                lower[c - 'a'] = true;
            } else {
                upper[c - 'A'] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (lower[i] && upper[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
