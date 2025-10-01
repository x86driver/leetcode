class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        set<int> s;
        int start_index = 0;
        while (nums.size() > 0 || start_index >= nums.size()) {
            if (nums.size() - start_index < 3) {
                if (nums.size() - start_index == 2) {
                    if (nums[start_index] == nums[start_index + 1]) {
                        ++ops;
                    }
                }
                break;
            }
            bool distinct = true;
            for (int i = start_index; i < nums.size(); ++i) {
                if (s.find(nums[i]) == s.end()) {
                    s.insert(nums[i]);
                } else {
                    start_index += 3;
                    s.clear();
                    ++ops;
                    distinct = false;
                    break;
                }
            }
            if (distinct) {
                break;
            }
        }
        return ops;
    }
};
