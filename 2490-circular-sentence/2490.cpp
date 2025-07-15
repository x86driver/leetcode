class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);
        vector<string> tokens;
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        for (int i = 0; i < tokens.size() - 1; ++i) {
            if (tokens[i].back() != tokens[i + 1][0]) {
                return false;
            }
        }
        if (tokens.back().back() != tokens[0][0]) {
            return false;
        }
        return true;
    }
};
