class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> counting(20002);
        int mid = 10000;
        for (int n : nums)
            ++counting[mid + n];

        int index = counting.size() - 1;
        while (k > 0) {
            while (counting[index] > 0) {
                --k;
                --counting[index];
                if (k == 0)
                    goto out;
            }
            --index;
        }

out:
        return index - mid;
    }
};
