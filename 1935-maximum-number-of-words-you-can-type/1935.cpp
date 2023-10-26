class Solution {
private:
    vector<string> split(const string text) {
        vector<string> res;
        istringstream iss(text);
        string word;
        while (iss >> word)
            res.push_back(word);
        return res;
    }
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> words = split(text);
        int count = 0;
        set<char> s;
        for (const char broken : brokenLetters) {
            s.insert(broken);
        }
        for (const string& word : words) {
            bool b = true;
            for (const char ch : word) {
                if (s.find(ch) != s.end()) {
                    b = false;
                    break;
                }
            }
            if (b)
                ++count;
        }
        return count;
    }
};
