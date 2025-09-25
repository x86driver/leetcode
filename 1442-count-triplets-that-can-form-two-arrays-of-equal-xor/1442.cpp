class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size() - 1; ++i) {
            int a = 0;
            for (int j = i; j < arr.size() - 1; ++j) {
                a ^= arr[j];
                int b = 0;
                for (int k = j + 1; k < arr.size(); ++k) {
                    b ^= arr[k];
                    if (a == b) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
