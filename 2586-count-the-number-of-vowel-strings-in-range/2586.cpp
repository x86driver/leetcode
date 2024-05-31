class Solution {
private:
    static inline bool vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    static inline bool isVowel(const string& word) {
        return vowel(word[0]) && vowel(word.back());
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            if (isVowel(words[i]))
                ++count;
        }
        return count;
    }
};
