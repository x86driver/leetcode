class Solution {
public:
    string replaceDigits(string s) {
        string ans;
        for (int i = 0; i < s.size() - 1; i += 2) {
            char c = s[i];
            ans += c;
            int x = s[i + 1] - '0';
            c += x;
            ans += c;
        }
        if (isalpha(s.back()))
            ans += s.back();
        return ans;
    }
};
