class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t size = nums.size() / 2;
        unordered_map<int, int> map;
        for (auto n : nums) {
            if (map.find(n) == map.end()) {
                map[n] = 1;
            } else {
                ++map[n];
                if (map[n] > size) {
                    return n;
                }
            }
        }

        return nums[0];
    }
};
