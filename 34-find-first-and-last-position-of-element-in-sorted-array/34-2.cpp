class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }

        if (right == -1 || nums[right] != target)
            return {-1, -1};
        int last_right = right;

        left = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }

        return {right, last_right};
    }
};
