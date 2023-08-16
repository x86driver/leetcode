class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        set<int> ans;
        for (int n : s1) {
            if (s2.find(n) != s2.end() || s3.find(n) != s3.end())
                ans.insert(n);
        }
        for (int n : s2) {
            if (s3.find(n) != s3.end())
                ans.insert(n);
        }

        vector<int> result(ans.begin(), ans.end());
        return result;
    }
};
