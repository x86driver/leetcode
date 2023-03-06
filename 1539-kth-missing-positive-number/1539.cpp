class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int base = 1000;
        arr.insert(arr.begin(), 0);
        if (arr.back() != 1000) {
            arr.push_back(1000);
            base = 999;
        }
        size_t i = 1;
        for (; i < arr.size(); ++i) {
            k -= arr[i] - arr[i - 1] - 1;
            if (k <= 0)
                break;
        }
        if (k > 0)
            return base + k;
        else
            return arr[i] + k - 1;
    }
};
