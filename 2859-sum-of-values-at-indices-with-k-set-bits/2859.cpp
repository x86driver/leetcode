class Solution {
private:
    int bits(int n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += n & 0x01;
            n >>= 1;
        }
        return count;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (bits(i) == k)
                ans += nums[i];
        }
        return ans;
    }
};
