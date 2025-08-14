class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream iss(text);
        string token, token1, token2;
        vector<string> tokens;
        while (iss >> token) {
            if (token1.empty()) {
                token1 = token;
            } else if (token2.empty()) {
                token2 = token;
            }
            if (!token1.empty() && !token2.empty()) {
                tokens.push_back(token1 + " " + token2);
                token1 = token2;
                token2.clear();
            }
        }

        vector<string> ans;
        const string combine = first + " " + second;
        for (int i = 0; i < tokens.size() - 1; ++i) {
            if (combine == tokens[i]) {
                string third = tokens[i + 1];
                string tmp;
                bool found = false;
                for (int k = 0; k < third.size(); ++k) {
                    if (found) {
                        tmp += third[k];
                    }
                    if (third[k] == ' ') {
                        found = true;
                    }
                }
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};
