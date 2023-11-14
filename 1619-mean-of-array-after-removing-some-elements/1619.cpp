class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int drops = arr.size() * 0.05;
        arr.erase(arr.end() - drops, arr.end());
        arr.erase(arr.begin(), arr.begin() + drops);
        int sum = 0;
        for (int n : arr)
            sum += n;
        return (double)sum / arr.size();
    }
};
