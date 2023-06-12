class Solution {
private:
    vector<string> splitString(const string& s) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, ' ')) {
            tokens.push_back(token);
        }
        return tokens;
    }
public:
    string reverseWords(string s) {
        vector<string> tokens = splitString(s);
        string ans;
        for (string& token : tokens) {
            for (int i = 0; i < token.size() / 2; ++i) {
                swap(token[i], token[token.size() - i - 1]);
            }
            ans += move(token) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
