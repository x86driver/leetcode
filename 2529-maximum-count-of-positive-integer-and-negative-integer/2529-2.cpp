class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= 0)
                right = mid;
            else
                left = mid + 1;
        }

        int negative = right;

        left = 0;
        right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > 0)
                right = mid;
            else
                left = mid + 1;
        }

        int positive = nums.size() - right;

        return max(negative, positive);
    }
};
