class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> ms, mt;
        for (char c : s) {
            ++ms[c];
        }
        for (char c : t) {
            ++mt[c];
        }
        int ans = 0;
        for (const pair<char, int>& p : mt) {
            int diff = p.second - ms[p.first];
            if (diff > 0) {
                ans += diff;
            }
        }
        return ans;
    }
};
