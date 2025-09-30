class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        int sum = INT_MAX;
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); ++i) {
            if (m.find(nums1[i]) == m.end()) {
                m[nums1[i]] = i;
            }
        }

        for (int i = 0; i < nums2.size(); ++i) {
            if (m.find(nums2[i]) != m.end()) {
                sum = min(sum, m[nums2[i]] + i);
            }
        }

        if (sum == INT_MAX) {
            return -1;
        } else {
            return sum;
        }
    }
};
