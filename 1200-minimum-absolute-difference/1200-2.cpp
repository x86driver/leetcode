class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; ++i) {
            int tmpdiff = arr[i + 1] - arr[i];
            if (tmpdiff < diff) {
                ans.clear();
            }
            if (tmpdiff <= diff) {
                diff = tmpdiff;
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
