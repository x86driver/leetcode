class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elemSum = accumulate(nums.begin(), nums.end(), 0);
        int digitSum = 0;
        for (int n : nums) {
            while (n) {
                digitSum += n % 10;
                n /= 10;
            }
        }
        return abs(elemSum - digitSum);
    }
};
