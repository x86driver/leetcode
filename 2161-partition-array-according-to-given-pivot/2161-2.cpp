class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        for (int n : nums) {
            if (n < pivot) {
                ans[left++] = n;
            } else if (n > pivot) {
                ans[right--] = n;
            } else {
                ++count;
            }
        }
        while (count--) {
            ans[left++] = pivot;
        }
        reverse(ans.begin() + right + 1, ans.end());

        return ans;
    }
};
