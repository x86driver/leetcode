class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (const string& setence : sentences) {
            int words = 0;
            for (char c : setence) {
                if (c == ' ') {
                    ++words;
                }
            }
            ans = max(ans, words);
        }
        return ans + 1;
    }
};
