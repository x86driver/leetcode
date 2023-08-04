class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> seta;
        vector<int> ans(A.size());

        for (int i = 0; i < A.size(); ++ i) {
            seta.insert(A[i]);
            int count = 0;
            for (int j = 0; j <= i; ++j) {
                if (seta.find(B[j]) != seta.end())
                    ++count;
            }
            ans[i] = count;
        }
        return ans;
    }
};
