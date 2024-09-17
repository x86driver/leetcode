class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int min1 = 1001;
        int min2 = 1001;
        for (int n : nums1) {
            min1 = min(min1, n);
        }
        for (int n : nums2) {
            min2 = min(min2, n);
        }
        return min2 - min1;
    }
};
