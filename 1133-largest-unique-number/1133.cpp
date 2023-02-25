class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums)
            ++m[n];

        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            pair<int, int> p = *it;
            if (p.second == 1)
                return p.first;
        }

        return -1;
    }
};
