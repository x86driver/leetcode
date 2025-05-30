class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> m(10);
        for (int n : digits) {
            ++m[n];
        }
        vector<int> ans;
        for (int i = 100; i < 999; i += 2) {
            vector<int> arr = m;
            bool valid = true;
            int val = i;
            while (val) {
                --arr[val % 10];
                val /= 10;
            }
            for (int n : arr) {
                if (n < 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
