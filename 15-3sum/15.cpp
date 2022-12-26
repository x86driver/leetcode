class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());

        for (auto i = 0; i < nums.size(); ++i)  {
            auto head = i + 1;
            auto tail = nums.size() - 1;
            while (head < tail) {
                int result = nums[i] + nums[head] + nums[tail];
                if (result == 0) {
                    vector<int> candidate = {nums[i], nums[head], nums[tail]};
                    if (s.find(candidate) == s.end()) {
                        ans.push_back({nums[i], nums[head], nums[tail]});
                        s.insert(candidate);
                    }
                }
                if (result > 0) {
                    --tail;
                } else {
                    ++head;
                }
            }
        }

        return ans;
    }
};
