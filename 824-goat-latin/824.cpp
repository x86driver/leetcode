class Solution {
private:
    bool vowel(const string& s) {
        return (!s.empty()
                && s[0] == 'a' || s[0] == 'A'
                || s[0] == 'e' || s[0] == 'E'
                || s[0] == 'i' || s[0] == 'I'
                || s[0] == 'o' || s[0] == 'O'
                || s[0] == 'u' || s[0] == 'U');
    }
public:
    string toGoatLatin(string sentence) {
        istringstream iss(sentence);
        string token;
        vector<string> tokens;
        while (iss >> token) {
            if (!token.empty())
                tokens.push_back(token);
        }

        for (int i = 0; i < tokens.size(); ++i) {
            string& str = tokens[i];
            if (!vowel(str)) {
                char c = str[0];
                str.erase(0, 1);
                str += c;
            }
            str += "ma";
            for (int j = 0; j < i + 1; ++j)
                str += 'a';
        }

        string ans;
        for (const string& str : tokens)
            ans += str + " ";
        ans.pop_back();
        return ans;
    }
};
