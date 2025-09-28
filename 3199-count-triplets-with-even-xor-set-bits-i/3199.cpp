class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int count = 0;
        for (int n1 : a) {
            for (int n2 : b) {
                for (int n3 : c) {
                    int result = n1 ^ n2 ^ n3;
                    if ((__builtin_popcount((unsigned)result) & 1) == 0) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
