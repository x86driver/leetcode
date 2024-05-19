class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<bool> m1(101);
        vector<bool> m2(101);
        vector<bool> m3(101);
        for (int n : nums1)
            m1[n] = true;
        for (int n : nums2)
            m2[n] = true;
        for (int n : nums3)
            m3[n] = true;
        vector<int> ans;
        for (int i = 1; i < m1.size(); ++i) {
            if ((m1[i] + m2[i] + m3[i]) >= 2)
                ans.push_back(i);
        }
        return ans;
    }
};
