class Solution {
private:
    bool isPattern(string& word, string& pattern) {
        map<char, char> m1, m2;
        for (size_t i = 0; i < word.size(); ++i) {
            if (m2.find(pattern[i]) == m2.end()) {
                m1[word[i]] = pattern[i];
                m2[pattern[i]] = word[i];
            }
        }
        string trans;
        for (char c : word)
            trans += m1[c];
        return trans == pattern;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string& word : words)
            if (isPattern(word, pattern))
                ans.push_back(word);
        return ans;
    }
};
