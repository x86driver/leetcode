class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> m(2001);
        for (int n : arr)
            ++m[n + 1000];
        vector<int> occurs(1001);
        for (int n : m) {
            if (n == 0)
                continue;
            if (occurs[n] != 0)
                return false;
            occurs[n] = 1;
        }
        return true;
    }
};
