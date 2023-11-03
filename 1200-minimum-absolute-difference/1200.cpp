class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> prefix;
        sort(arr.begin(), arr.end());

        int minimum = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            int val = arr[i] - arr[i - 1];
            minimum = min(minimum, val);
            prefix.push_back(val);
        }

        for (int i = 0; i < prefix.size(); ++i) {
            if (prefix[i] == minimum) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};
