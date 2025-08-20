class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());

        vector<int> ans;
        for (int i = 0; i < odd.size(); ++i) {
            ans.push_back(even[i]);
            ans.push_back(odd[i]);
        }

        if (even.size() > odd.size()) {
            ans.push_back(even.back());
        }

        return ans;
    }
};
