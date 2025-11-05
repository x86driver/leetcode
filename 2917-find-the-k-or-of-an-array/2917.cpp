class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if ((nums[j] & 0x80000000) == 0x80000000) {
                    ++count;
                }
                nums[j] <<= 1;
            }
            ans <<= 1;
            if (count >= k) {
                ans |= 1;
            }
        }
        return ans;
    }
};
