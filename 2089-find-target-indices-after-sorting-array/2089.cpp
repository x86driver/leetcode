class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> arr(101);
        for (int n : nums)
            ++arr[n];
        vector<int> ans;
        int index = 0;
        for (int i = 1; i < target; ++i) {
            index += arr[i];
        }
        for (int i = 0; i < arr[target]; ++i) {
            ans.push_back(index++);
        }
        return ans;
    }
};
