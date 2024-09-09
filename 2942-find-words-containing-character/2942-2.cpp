class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); ++i) {
            const string& str = words[i];
            for (char c : str) {
                if (c == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
