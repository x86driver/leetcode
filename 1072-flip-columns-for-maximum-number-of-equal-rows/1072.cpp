class Solution {
private:
    string generateRow(const vector<int>& row) {
        string ret = "*";
        for (int i = 1; i < row.size(); ++i) {
            if (row[i] != row[i - 1]) {
                ret += '|';
            }
            ret += '*';
        }
        return ret;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> m;
        int ans = 0;
        for (vector<int>& row : matrix) {
            string gen_row = generateRow(row);
            ++m[gen_row];
            ans = max(ans, m[gen_row]);
        }
        return ans;
    }
};
