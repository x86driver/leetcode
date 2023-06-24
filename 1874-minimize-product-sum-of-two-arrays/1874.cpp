class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int sum = 0;
        vector<int> buckets(101);
        for (int n2 : nums2) {
            ++buckets[n2];
        }
        sort(nums1.begin(), nums1.end(), greater<int>());
        int index2 = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            while (index2 < buckets.size() && buckets[index2] == 0)
                ++index2;
            sum += nums1[i] * index2;
            --buckets[index2];
        }
        return sum;
    }
};
