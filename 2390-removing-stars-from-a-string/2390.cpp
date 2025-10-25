class Solution {
public:
    string removeStars(string s) {
        string ans;
        int stars = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '*') {
                ++stars;
            } else if (stars) {
                while (stars && s[i] != '*') {
                    --i;
                    --stars;
                }
                ++i;
            } else {
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
