class Solution {
private:
    bool hasReplacement(const string& text) {
        for (char c : text) {
            if (c == '%') {
                return true;
            }
        }
        return false;
    }
    string substitute(map<char, string>& m, const string& text) {
        string ret;
        int i = 0;
        while (i < text.size()) {
            if (text[i] == '%') {
                if (m.find(text[i + 1]) != m.end()) {
                    ret += m[text[i + 1]];
                    i += 3;
                } else {
                    ret += text[i + 1];
                    i += 3;
                }
            } else {
                ret += text[i];
                ++i;
            }
        }
        return ret;
    }
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        map<char, string> m;
        for (const vector<string>& mapping : replacements) {
            m[mapping[0][0]] = mapping[1];
        }

        string ans = text;
        do {
            ans = substitute(m, ans);
        } while (hasReplacement(ans));

        return ans;
    }
};
