class Solution {
public:
    int totalReplacements(vector<int>& ranks) {
        int replace = 0;
        int curr = ranks[0];
        for (int r : ranks) {
            if (r < curr) {
                ++replace;
                curr = r;
            }
        }
        return replace;
    }
};
