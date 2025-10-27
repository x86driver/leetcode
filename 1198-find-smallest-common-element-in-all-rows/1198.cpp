class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> m(10001);
        for (const vector<int>& row : mat) {
            for (int n : row) {
                ++m[n];
            }
        }
        int target = mat.size();
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] == target) {
                return i;
            }
        }
        return -1;
    }
};
