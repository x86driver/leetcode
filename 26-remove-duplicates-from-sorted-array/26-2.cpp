class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int count = 0;

        while (j < nums.size()) {
            while ((j + 1) < nums.size() && nums[j + 1] == nums[j])
                ++j;
            nums[i] = nums[j];
            ++i;
            ++j;
            ++count;
        }
        return count;
    }
};
