class Solution {
public:
    int findMin(vector<int>& nums, int left, int right) {
        while (left < right) {
            if (nums[left] < nums[right])
                return nums[left];
            int mid = (left + right) / 2;
            if (nums[mid] == nums[right])
                if (right - mid == 1)
                    return nums[right];
                else
                    return min(findMin(nums, left, mid), findMin(nums, mid, right));
            else if (nums[mid] <= nums[right])
                right = mid;
            else
                left = mid + 1;
        }

        return nums[right];
    }

    int findMin(vector<int>& nums) {
        if (nums.size() >= 2 && nums[0] < nums.back())
            return nums[0];

        int left = 0;
        int right = nums.size() - 1;

        return findMin(nums, left, right);
    }
};
