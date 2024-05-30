class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        string tmp;
        for (const string& word : words) {
            for (char c : word) {
                if (c == separator && !tmp.empty()) {
                    ans.push_back(tmp);
                    tmp.clear();
                } else if (c != separator) {
                    tmp += c;
                }
            }
            if (!tmp.empty()) {
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};
