class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums)
            ++m[n];
        int times = nums.size() / 2 + 1;
        for (int n : nums) {
            if (m[n] >= times)
                return n;
        }
        return nums[0];
    }
};
