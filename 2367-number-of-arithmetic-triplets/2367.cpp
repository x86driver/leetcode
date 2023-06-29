class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]] = i;

        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] - nums[i] != diff)
                    continue;
                int target = nums[j] + diff;
                if (m.find(target) != m.end() && m[target] > i && m[target] > j)
                    ++count;
            }
        }

        return count;
    }
};
