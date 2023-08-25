class Solution {
private:
    int countOnes(vector<int>& row) {
        int count = 0;
        for (int n : row)
            count += n;
        return count;
    }
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maximum = 0;
        int maxindex = -1;
        for (int i = mat.size() - 1; i >= 0; --i) {
            int count = countOnes(mat[i]);
            if (count >= maximum) {
                maximum = count;
                maxindex = i;
            }
        }
        return {maxindex, maximum};
    }
};
