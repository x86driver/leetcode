class Solution {
public:
    string freqAlphabets(string s) {
        int i = s.size() - 1;
        string ans;
        while (i >= 0) {
            int digits = 0;
            if (s[i] == '#') {
                digits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                i -= 3;
            } else {
                digits = s[i] - '0';
                --i;
            }
            ans += digits + 'a' - 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
