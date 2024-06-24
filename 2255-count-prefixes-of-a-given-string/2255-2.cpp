class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (const string& word : words) {
            if (word.size() > s.size())
                continue;
            ++count;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != s[i]) {
                    --count;
                    break;
                }
            }
        }
        return count;
    }
};
