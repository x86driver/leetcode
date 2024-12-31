class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        int maxSame = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums1.size(); j++) {
                if (nums1[j] == nums2[j]) {
                    ++count;
                }
            }
            maxSame = max(maxSame, count);
            rotate(nums1.rbegin(), nums1.rbegin() + 1, nums1.rend());
        }
        return maxSame;
    }
};
