class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            a += nums[i];
            int tmp = nums[i];
            while (tmp) {
                b += tmp % 10;
                tmp /= 10;
            }
        }

        return abs(a - b);
    }
};
