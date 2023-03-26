class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        vector<bool> counting(N);

        for (vector<int>& row : matrix) {
            for (int n : row) {
                if (n <= N && counting[n - 1] == false) {
                    counting[n - 1] = true;
                } else {
                    return false;
                }
            }
            for (int i = 0; i < N; ++i)
                if (counting[i] == false)
                    return false;
                else
                    counting[i] = false;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int n = matrix[j][i];
                if (n <= N && counting[n - 1] == false)
                    counting[n - 1] = true;
                else
                    return false;
            }

            for (int i = 0; i < N; ++i)
                if (counting[i] == false)
                    return false;
                else
                    counting[i] = false;
        }

        return true;
    }
};
