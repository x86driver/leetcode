class Solution {
private:
    void reverseString(string& s) {
        for (int i = 0; i < s.size() / 2; ++i)
            swap(s[i], s[s.size() - i - 1]);
    }
public:
    string finalString(string s) {
        int i = 0;
        string ans;
        while (i < s.size()) {
            if (s[i] == 'i') {
                if (i < s.size() - 1 && s[i + 1] == 'i') {
                    i += 2;
                    continue;
                }
                reverseString(ans);
            } else
                ans += s[i];
            ++i;
        }
        return ans;
    }
};
