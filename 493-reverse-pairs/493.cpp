class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        const int size = right - left + 1;
        vector<int> temp(size);
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
            temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];

        while (i <= mid)
            temp[k++] = nums[i++];

        while (j <= right)
            temp[k++] = nums[j++];

        i = left;
        k = 0;
        while (k < size)
            nums[i++] = temp[k++];
    }

    void calculate(vector<int>& nums, int left, int mid, int right) {
        int i = 0;
        int j = 0;
        for (i = left, j = mid; i <= mid; ++i) {
            while (j < right && nums[i] > 2L * nums[j + 1])
                ++j;
            ans += j - mid;
        }

    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        calculate(nums, left, mid, right);
        merge(nums, left, mid, right);
    }

    int ans;

public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};
