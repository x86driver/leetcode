class Solution {
public:
    int maxSameLengthRuns(string s) {
        map<int, int> m;
        int len = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++len;
            } else {
                ++m[len];
                len = 1;
            }
        }
        ++m[len];
        int ans = 0;
        for (const pair<int, int>& p : m) {
            ans = max(ans, p.second);
        }

        return ans;
    }
};
