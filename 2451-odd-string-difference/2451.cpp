class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, vector<string>> m;
        for (const string& word : words) {
            vector<int> diff;
            for (int i = 1; i < word.size(); ++i) {
                diff.push_back(word[i] - word[i - 1]);
            }
            m[diff].push_back(word);
        }
        for (const pair<vector<int>, vector<string>>& p : m) {
            if (p.second.size() == 1) {
                return p.second[0];
            }
        }
        return "";
    }
};
