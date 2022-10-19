class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        for (size_t i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (auto &str : strs) {
                if (str[i] != c) {
                    return ret;
                }
            }
            ret += c;
        }

        return ret;
    }
};
