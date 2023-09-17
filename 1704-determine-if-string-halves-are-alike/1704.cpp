class Solution {
private:
    bool isVowel(const char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    bool halvesAreAlike(string s) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < s.size() / 2; ++i)
            if (isVowel(s[i]))
                ++a;
        for (int i = s.size() / 2; i < s.size(); ++i)
            if (isVowel(s[i]))
                ++b;

        return a == b;
    }
};
