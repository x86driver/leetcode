class Solution {
public:
    int splittable(vector<int>& nums, int k, int T) {
        int sum = 0;
        --k;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum + nums[i] <= T) {
                sum += nums[i];
            } else if (nums[i] <= T) {
                sum = nums[i];
                --k;
            } else {
                return -1;
            }
        }

        return k;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums)
            sum += n;

        int left = 0;
        int right = sum;
        while (left < right) {
            int mid = (left + right) / 2;
            int split = splittable(nums, k, mid);
            if (split >= 0)
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
};
