class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int gi = 0;
        int si = 0;
        while (gi < g.size() && si < s.size()) {
            if (s[si] >= g[gi]) {
                ++count;
                ++si;
                ++gi;
            } else {
                ++si;
            }
        }
        return count;
    }
};
