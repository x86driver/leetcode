class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> counting(101);
        for (int num : nums) {
            ++counting[num];
        }
        vector<int> ans;
        for (int num : nums) {
            int small = 0;
            for (int i = 0; i < num; ++i) {
                small += counting[i];
            }
            ans.push_back(small);
        }
        return ans;
    }
};
