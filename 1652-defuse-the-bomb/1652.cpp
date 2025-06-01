class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int elems = code.size();
        if (k == 0) {
            vector<int> ans(code.size());
            return ans;
        } else {
            code.insert(code.end(), code.begin(), code.end());
        }

        vector<int> ans;
        for (int i = 0; i < elems; ++i) {
            int sum = 0;
            int start = i + 1;
            int end = start + k;
            if (k < 0) {
                start = i + elems + k;
                end = start - k;
            }
            for (; start < end; ++start) {
                sum += code[start];
            }
            ans.push_back(sum);
        }

        return ans;
    }
};
