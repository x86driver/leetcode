class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> m(101);
        for (const vector<int>& n : nums) {
            for (int i = n[0]; i <= n[1]; ++i)
                m[i] = true;
        }
        int ans = 0;
        for (bool b : m)
            if (b)
                ++ans;
        return ans;
    }
};
