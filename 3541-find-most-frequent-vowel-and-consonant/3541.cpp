class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> m(26);
        for (char c : s) {
            ++m[c - 'a'];
        }
        int vowels = 0;
        int consonants = 0;
        for (int i = 0; i < m.size(); ++i) {
            if (i == ('a' - 'a') || i == ('e' - 'a') || i == ('i' - 'a') || i == ('o' - 'a') || i == 'u' - 'a') {
                vowels = max(vowels, m[i]);
            } else {
                consonants = max(consonants, m[i]);
            }
        }

        return vowels + consonants;
    }
};
