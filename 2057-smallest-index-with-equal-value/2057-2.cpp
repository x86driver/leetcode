class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int smallest = 101;
        for (int i = 0; i < nums.size(); ++i) {
            if ((i % 10) == nums[i]) {
                smallest = min(smallest, i);
            }
        }
        if (smallest == 101)
            return -1;
        return smallest;
    }
};
