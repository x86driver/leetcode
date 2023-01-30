class Solution {
public:
    bool splittable(vector<int>& nums, int k, int T) {
        int sum = 0;
        --k;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum + nums[i] <= T) {
                sum += nums[i];
            } else {
                sum = nums[i];
                --k;
            }
        }

        return k >= 0;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for (int n : nums) {
            left = max(left, n);
            right += n;
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (splittable(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
};
