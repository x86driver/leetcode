class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        set<int> s2(arr2.begin(), arr2.end());
        set<int> s3(arr3.begin(), arr3.end());
        vector<int> ans;
        for (int n : arr1) {
            if (s2.find(n) != s2.end() && s3.find(n) != s3.end()) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};
