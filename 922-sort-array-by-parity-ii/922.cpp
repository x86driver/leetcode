class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odds;
        vector<int> evens;
        for (int n : nums) {
            if ((n % 2) == 0) {
                evens.push_back(n);
            } else {
                odds.push_back(n);
            }
        }
        vector<int> ans(nums.size());
        int even_index = 0;
        int odd_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if ((i % 2) == 0) {
                ans[i] = evens[even_index++];
            } else {
                ans[i] = odds[odd_index++];
            }
        }
        return ans;
    }
};
