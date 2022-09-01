class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int> tmp = heights;
        std::sort(tmp.begin(), tmp.end());

        for (auto i = 0; i < heights.size(); ++i) {
            if (heights[i] != tmp[i]) {
                ++ans;
            }
        }
        return ans;
    }
};
