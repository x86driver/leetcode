class Solution {
private:
    int negatives(vector<int>& arr) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= 0)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        vector<int> col;
        for (int i = 0; i < grid.size(); ++i) {
            col.push_back(grid[i][0]);
        }
        int target = negatives(col);
        count += (grid.size() - target) * grid[0].size();
        for (int i = 0; i < target; ++i) {
            count += grid[i].size() - negatives(grid[i]);
        }
        return count;
    }
};
