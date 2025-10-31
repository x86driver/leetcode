class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix_xor;
        prefix_xor.push_back(arr[0]);
        for (int i = 1; i < arr.size(); ++i) {
            prefix_xor.push_back(prefix_xor[i - 1] ^ arr[i]);
        }

        vector<int> ans;
        for (const vector<int>& query :queries) {
            int start = query[0];
            int end = query[1];
            if (start == 0) {
                ans.push_back(prefix_xor[end]);
                continue;
            } else if (start == end) {
                ans.push_back(arr[end]);
                continue;
            }

            int tmp = prefix_xor[end] ^ prefix_xor[start - 1];
            ans.push_back(tmp);
        }

        return ans;
    }
};
