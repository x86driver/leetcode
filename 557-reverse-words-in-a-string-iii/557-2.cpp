class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string token;
        string ans;
        while (iss >> token) {
            if (token.size() > 0) {
                for (int i = 0; i < token.size() / 2; ++i) {
                    swap(token[i], token[token.size() - i - 1]);
                }
            }
            ans += token + " ";
        }
        if (ans.size() > 0) {
            ans.pop_back();
        }
        return ans;
    }
};
