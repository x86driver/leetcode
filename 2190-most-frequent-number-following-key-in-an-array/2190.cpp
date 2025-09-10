class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == key) {
                ++m[nums[i + 1]];
            }
        }
        int count = 0;
        int ans = 0;
        for (const pair<int, int>& p : m) {
            if (p.second >= count) {
                count = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};
