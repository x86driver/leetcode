class Solution {
public:
    int countAsterisks(string s) {
        vector<string> tokens;
        string token;
        stringstream tokenStream(s);
        int index = 0;
        while (getline(tokenStream, token, '|')) {
            if ((index % 2) == 0) {
                tokens.push_back(token);
            }
            ++index;
        }

        int count = 0;
        for (const string &str : tokens)
            for (char c : str)
                if (c == '*')
                    ++count;

        return count;
    }
};
