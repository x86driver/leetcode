class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            set<int> sets;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] != -1 && sets.find(nums[j]) == sets.end()) {
                    sets.insert(nums[j]);
                    nums[j] = -1;
                }
            }
            if (!sets.empty()) {
                vector<int> row(sets.begin(), sets.end());
                ans.push_back(row);
            }
        }
        return ans;
    }
};
