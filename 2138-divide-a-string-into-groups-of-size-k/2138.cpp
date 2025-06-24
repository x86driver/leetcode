class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int i = 0;
        vector<string> ans;
        while (i < s.size()) {
            string sub = s.substr(i, k);
            while (sub.size() < k) {
                sub += fill;
            }
            ans.push_back(sub);
            i += k;
        }
        return ans;
    }
};
