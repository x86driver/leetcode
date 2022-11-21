class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto n : nums) {
            if (map.find(n) == map.end()) {
                map[n] = 1;
            } else {
                ++map[n];
            }
        }

        int sum = 0;
        for (auto m : map) {
            if (m.second == 1) {
                sum += m.first;
            }
        }

        return sum;
    }
};
