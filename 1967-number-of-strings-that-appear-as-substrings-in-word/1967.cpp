class Solution {
private:
    bool isSubstr(const string& pattern, const string& word) {
        for (int i = 0; i < word.size(); ++i) {
            if (pattern == word.substr(i, pattern.size()))
                return true;
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& pattern : patterns) {
            if (isSubstr(pattern, word))
                ++count;
        }

        return count;
    }
};
