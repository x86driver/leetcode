class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        int d = m.size() - k;
        if (d <= 0) {
            return 0;
        }
        vector<int> counts;
        for (const pair<char, int>& p : m) {
            counts.push_back(p.second);
        }
        sort(counts.begin(), counts.end());
        int ans = 0;
        for (int i = 0; i < counts.size() - k; ++i) {
            ans += counts[i];
        }
        return ans;
    }
};
