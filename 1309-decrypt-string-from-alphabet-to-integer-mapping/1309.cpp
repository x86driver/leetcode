class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for (int i = 0; i < s.size();) {
            int n = 0;
            if ((i + 2) < s.size() && s[i + 2] == '#') {
                n = stoi(s.substr(i, 2));
                i += 3;
            } else {
                n = s[i] - '0';
                ++i;
            }
            ans += 'a' + n - 1;
        }

        return ans;
    }
};
