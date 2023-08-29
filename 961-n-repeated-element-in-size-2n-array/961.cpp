class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums) {
            ++m[n];
            if (m[n] >= (nums.size() / 2))
                return n;
        }
        return 0;
    }
};
