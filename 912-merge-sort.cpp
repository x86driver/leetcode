class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            tmp[k++] = (nums[i] < nums[j] ? nums[i++] : nums[j++]);
        }

        while (i <= mid)
            tmp[k++] = nums[i++];
        while (j <= right)
            tmp[k++] = nums[j++];

        i = left;
        k = 0;

        while (i <= right) {
            nums[i++] = tmp[k++];
        }
//        copy(tmp.begin(), tmp.end(), nums.begin() + left);
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
