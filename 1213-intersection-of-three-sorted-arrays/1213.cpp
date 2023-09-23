class Solution {
private:
    bool exist(vector<int>& arr, int val) {
        int left = -1;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (arr[mid] == val)
                return true;
            else if (arr[mid] < val)
                left = mid;
            else
                right = mid - 1;
        }
        return false;
    }
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for (int val : arr1) {
            if (exist(arr2, val) && exist(arr3, val))
                ans.push_back(val);
        }
        return ans;
    }
};
