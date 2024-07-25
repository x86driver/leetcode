class Solution {
private:
    bool isSubstring(const string& a, const string& word) {
        int i = 0;
        while (i < word.size()) {
            if (word[i] == a[0]) {
                const string &s = word.substr(i, a.size());
                if (a == s)
                    return true;
            }
            ++i;
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& pattern : patterns) {
            if (pattern.size() > word.size())
                continue;
            if (isSubstring(pattern, word))
                ++count;
        }
        return count;
    }
};
