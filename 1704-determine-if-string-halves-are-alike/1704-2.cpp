class Solution {
private:
    static inline int vowels(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    ++count;
                }
        }
        return count;
    }
public:
    bool halvesAreAlike(string s) {
        int half = s.size() / 2;
        int a = vowels(s.substr(0, half));
        int b = vowels(s.substr(half));

        return a == b;
    }
};
