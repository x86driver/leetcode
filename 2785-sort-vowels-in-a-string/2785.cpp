class Solution {
private:
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int vidx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                s[i] = vowels[vidx++];
            }
        }
        return s;
    }
};
