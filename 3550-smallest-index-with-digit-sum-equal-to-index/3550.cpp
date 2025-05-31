class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans = 1001;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            int sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            if (i == sum) {
                ans = min(ans, sum);
            }
        }
        if (ans == 1001) {
            return -1;
        }
        return ans;
    }
};
