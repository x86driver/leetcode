class Solution {
private:
    int nbits(int num) {
        int count = 0;
        while (num) {
            if ((num & 1) == 1)
                ++count;
            num >>= 1;
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> m(32, vector<int>(10001));
        for (int a : arr) {
            int n = nbits(a);
            ++m[n][a];
        }
        vector<int> ans;
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < 10001; ++j) {
                while (m[i][j]) {
                    ans.push_back(j);
                    --m[i][j];
                }
            }
        }
        return ans;
    }
};
