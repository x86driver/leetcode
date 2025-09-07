class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            ++m[n];
        }
        for (const pair<int, int>&p : m) {
            if (p.second > 2) {
                return false;
            }
        }
        return true;
    }
};
