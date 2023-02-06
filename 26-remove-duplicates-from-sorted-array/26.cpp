class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();

        int ans = 1;
        int i = 0;
        int j = 1;

        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                while (j < nums.size())
                    if (nums[i] == nums[j])
                        ++j;
                    else
                        break;

                if (j >= nums.size())
                    break;
                ++i;
                nums[i] = nums[j];
                ++ans;
            } else {
                ++i;
                ++j;
                ++ans;
            }
        }

        return ans;
    }
};
