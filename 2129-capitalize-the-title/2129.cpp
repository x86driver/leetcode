class Solution {
public:
    string capitalizeTitle(string title) {
        string ans;
        istringstream iss(title);
        string token;
        while (iss >> token) {
            if (token.size() >= 3) {
                token[0] = toupper(token[0]);
                for (int i = 1; i < token.size(); ++i) {
                    token[i] = tolower(token[i]);
                }
            } else {
                for (int i = 0; i < token.size(); ++i) {
                    token[i] = tolower(token[i]);
                }
            }
            ans += token + " ";
        }
        ans.pop_back();
        return ans;
    }
};
