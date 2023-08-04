class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> m;
        for (int n : nums)
            ++m[n];
        int numbers = 0;
        int remain = 0;
        for (pair<int, int> p : m) {
            numbers += p.second / 2;
            remain += p.second % 2;
        }
        return {numbers, remain};
    }
};
