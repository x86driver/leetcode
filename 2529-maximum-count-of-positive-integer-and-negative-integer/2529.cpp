class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= 1)
                right = mid;
            else
                left = mid + 1;
        }

        int pos = right;

        left = -1;
        right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= -1)
                left = mid;
            else
                right = mid - 1;
        }

        int neg = right;

        if (pos >= nums.size())
            if (nums.back() == 0 && neg == -1)
                return 0;
            else if (neg >= 0)
                return neg + 1;
            else
                return nums.size();
        if (neg == -1)
            return nums.size() - pos;

        return max(static_cast<int>(nums.size() - pos), neg + 1);
    }
};
