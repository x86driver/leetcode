class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        for (int n : arr) {
            ++m[n];
        }
        int lucky = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (m[arr[i]] == arr[i]) {
                lucky = max(lucky, arr[i]);
            }
        }
        return lucky;
    }
};
