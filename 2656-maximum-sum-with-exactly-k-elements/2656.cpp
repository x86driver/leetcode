class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        auto it = max_element(nums.begin(), nums.end());
        int maximum = 0;
        int base = *it;
        for (int i = 0; i < k; ++i) {
            maximum += base;
            ++base;
        }
        return maximum;
    }
};
