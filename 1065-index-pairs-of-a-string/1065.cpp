class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for (const string& word : words) {
            for (int i = 0; i < text.size(); ++i) {
                int j = 0;
                bool found = true;
                while (j < word.size()) {
                    if (text[i + j] != word[j]) {
                        found = false;
                        break;
                    }
                    ++j;
                }
                if (found) {
                    ans.push_back({i, i + static_cast<int>(word.size()) - 1});
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
