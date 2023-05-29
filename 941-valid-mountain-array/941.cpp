class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        if (arr[1] <= arr[0])
            return false;

        bool decreasing = false;
        bool changed = false;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1] && !decreasing) {
                continue;
            }
            if (arr[i] < arr[i - 1] && !decreasing && !changed) {
                decreasing = true;
                changed = true;
            }
            if (arr[i] < arr[i - 1] && decreasing) {
                continue;
            }
            return false;
        }
        return decreasing && changed;
    }
};
