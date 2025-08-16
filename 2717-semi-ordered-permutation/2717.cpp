class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int x = -1;
        int y = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1 && x == -1) {
                x = i;
            }
            if (nums[i] == nums.size() && y == -1) {
                y = i;
            }
        }
        if (x < y) {
            return x + (nums.size() - y - 1);
        } else {
            return x + (nums.size() - y - 1) - 1;
        }
    }
};
