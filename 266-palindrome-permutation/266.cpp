class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        bool odd = false;
        for (const pair<char, int>& p : m) {
            if (p.second % 2 == 1) {
                if (odd) {
                    return false;
                }
                odd = true;
            }
        }
        return true;
    }
};
