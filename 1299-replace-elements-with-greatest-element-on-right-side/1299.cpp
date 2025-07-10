class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        ans.reserve(arr.size());
        for (int i = 0; i < arr.size() - 1; ++i) {
            int greatest = INT_MIN;
            for (int j = i + 1; j < arr.size(); ++j) {
                greatest = max(greatest, arr[j]);
            }
            ans.push_back(greatest);
        }
        ans.push_back(-1);
        return ans;
    }
};
