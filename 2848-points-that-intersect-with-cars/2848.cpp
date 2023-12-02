class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int count = 0;
        vector<bool> m(101);
        for (const vector<int> &num : nums) {
            for (int i = num[0]; i <= num[1]; ++i)
                m[i] = true;
        }
        for (int i = 1; i < 101; ++i)
            count += m[i];
        return count;
    }
};
