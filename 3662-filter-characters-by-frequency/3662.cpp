class Solution {
public:
    string filterCharacters(string s, int k) {
        string ans;
        map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        for (char c : s) {
            if (m[c] < k) {
                ans += c;
            }
        }
        return ans;
    }
};
