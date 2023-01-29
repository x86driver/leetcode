class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        int left = -1;
        int right = nums.size() - 1;
        while (right - left > 1) {
            int lmid = (left + right + 1) / 2;
            int rmid = lmid + 1;
            if (nums[lmid] <= nums[rmid])
                left = lmid;
            else
                right = rmid - 1;
        }

        return right;
    }
};
