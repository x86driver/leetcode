class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> m;
        for (int n : arr)
            ++m[n];

        int count = 0;
        for (int n : arr) {
            if (m.find(n + 1) != m.end())
                ++count;
        }

        return count;
    }
};
