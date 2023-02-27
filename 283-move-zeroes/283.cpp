class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_index = -1;
        int nums_index = -1;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zero_index = i;
                break;
            }
        }

        if (zero_index == -1)
            return;

        for (size_t i = zero_index + 1; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums_index = i;
                break;
            }
        }

        while (nums_index < nums.size()) {
            nums[zero_index] = nums[nums_index];
            nums[nums_index] = 0;
            ++zero_index;

            for (; nums_index < nums.size(); ++nums_index)
                if (nums[nums_index] != 0)
                    break;
        }

    }
};
