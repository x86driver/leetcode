class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<string> ans;
        int start = nums[0];
        int end = nums[0];
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == prev + 1) {
                end = nums[i];
                prev = nums[i];
            } else {
                if (start != end) {
                    ans.push_back(to_string(start) + "->" + to_string(end));
                } else {
                    ans.push_back(to_string(start));
                }
                start = end = prev = nums[i];
            }
        }

        if (start != end) {
            ans.push_back(to_string(start) + "->" + to_string(end));
        } else {
            ans.push_back(to_string(start));
        }

        return ans;
    }
};
