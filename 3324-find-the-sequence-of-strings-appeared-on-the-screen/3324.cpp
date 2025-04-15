class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string tmp = "a";
        for (char c : target) {
            ans.push_back(tmp);
            while (tmp.back() != c) {
                ++tmp.back();
                ans.push_back(tmp);
            }
            tmp += "a";
        }
        return ans;
    }
};
