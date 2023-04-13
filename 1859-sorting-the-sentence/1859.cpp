class Solution {
private:
    vector<string> splitString(const string &s) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);

        while (getline(tokenStream, token, ' ')) {
            if (token != "")
                tokens.push_back(token);
        }

        return tokens;
    }
public:
    string sortSentence(string s) {
        vector<string> tokens = splitString(s);
        vector<string> buckets(10);
        for (string& token : tokens) {
            int index = token.back() - '0';
            buckets[index] = token.substr(0, token.size() - 1);
        }

        string ans;
        for (string& b : buckets)
            if (b != "")
                ans += b + " ";

        return ans.substr(0, ans.size() - 1);
    }
};
