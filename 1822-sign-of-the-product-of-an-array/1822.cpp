class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                return 0;
            }
            if (nums[i] < 0) {
                nums[i] = -1;
            } else {
                nums[i] = 1;
            }
            product *= nums[i];
        }
        if (product > 0) {
            return 1;
        } else if (product == 0) {
            return 0;
        } else {
            return -1;
        }
    }
};
