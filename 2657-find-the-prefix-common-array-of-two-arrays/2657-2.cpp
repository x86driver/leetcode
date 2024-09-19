class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        set<int> s;
        for (int i = 0; i < A.size(); ++i) {
            int count = 0;
            s.insert(A[i]);
            for (int j = 0; j <= i; ++j) {
                if (s.find(B[j]) != s.end())
                    ++count;
            }
            ans[i] = count;
        }
        return ans;
    }
};
