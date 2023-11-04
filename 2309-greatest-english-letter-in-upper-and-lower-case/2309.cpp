class Solution {
public:
    string greatestLetter(string s) {
        const int ascii = 26 * 2 + 6;
        vector<bool> m(ascii);
        for (char c : s) {
            m[c - 'A'] = true;
        }
        for (int i = ascii - 1; i >= 26; --i) {
            if (m[i] && m[i - 26 - 6]) {
                string ret = "A";
                ret[0] += (i - 26 - 6);
                return ret;
            }
        }
        return "";
    }
};
