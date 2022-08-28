class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> mapping(nums.size()+1);
        vector<int> ans;

        for (auto &n: nums) {
            if (mapping[n] == 1) {
                ans.push_back(n);
            }
            mapping[n] = 1;
        }

        return ans;
    }
};
