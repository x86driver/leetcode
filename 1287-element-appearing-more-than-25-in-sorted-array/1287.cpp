class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1;
        int max_count = 0;
        int ans = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == arr[i - 1]) {
                ++count;
                if (count >= max_count) {
                    ans = arr[i];
                    max_count = count;
                }
            } else {
                count = 1;
            }
        }
        return ans;
    }
};
