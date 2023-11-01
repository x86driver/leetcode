class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (const string& word : words) {
            istringstream iss(word);
            string token;
            while (getline(iss, token, separator))
                if (!token.empty())
                    ans.push_back(token);
        }
        return ans;
    }
};
