class Solution {
private:
    string format(int start, int end) {
        if (end - start <= 1)
            return "";
        if (end - start == 2)
            return to_string(start + 1);
        return to_string(start + 1) + "->" + to_string(end - 1);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper + 1);

        for (size_t i = 0; i < nums.size() - 1; ++i) {
            int start = nums[i];
            int end = nums[i + 1];
            string s = format(start, end);
            if (s != "")
                ans.push_back(s);
        }

        return ans;
    }
};
