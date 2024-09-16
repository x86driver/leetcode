class Solution {
public:
    int countAsterisks(string s) {
        stringstream ss(s);
        vector<string> tokens;
        string token;
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }
        int count = 0;
        for (int i = 0; i < tokens.size(); i += 2) {
            for (char c : tokens[i]) {
                if (c == '*')
                    ++count;
            }
        }
        return count;
    }
};
