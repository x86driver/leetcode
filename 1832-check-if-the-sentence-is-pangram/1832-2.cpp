class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> m(26);
        for (char c : sentence) {
            m[c - 'a'] = true;
        }
        for (int i = 0; i < 26; ++i) {
            if (!m[i]) {
                return false;
            }
        }
        return true;
    }
};
