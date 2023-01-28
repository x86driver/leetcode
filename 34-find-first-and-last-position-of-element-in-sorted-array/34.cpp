class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }

        if (right < nums.size() && nums[right] == target)
            ans.push_back(right);
        else
            ans.push_back(-1);

        // left = -1;
        right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }

        if (right < nums.size() && nums[right] == target)
            ans.push_back(right);
        else
            ans.push_back(-1);

        return ans;
    }
};
