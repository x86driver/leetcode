class Solution {
public:
    string replaceDigits(string s) {
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            } else {
                char c = s[i - 1];
                c += s[i] - '0';
                ans += c;
            }
        }
        return ans;
    }
};
