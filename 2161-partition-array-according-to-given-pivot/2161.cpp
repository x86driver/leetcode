class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> pivots;
        vector<int> greater;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < pivot) {
                ans.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                pivots.push_back(nums[i]);
            } else {
                greater.push_back(nums[i]);
            }
        }
        ans.insert(ans.end(), make_move_iterator(pivots.begin()),
                              make_move_iterator(pivots.end()));
        ans.insert(ans.end(), make_move_iterator(greater.begin()),
                              make_move_iterator(greater.end()));
        return ans;
    }
};
