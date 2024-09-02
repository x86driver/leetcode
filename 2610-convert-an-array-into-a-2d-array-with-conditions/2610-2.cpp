class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> m(201);
        for (int n : nums)
            ++m[n];
        vector<vector<int>> ans;
        int size = nums.size();
        while (size) {
            vector<int> tmp;
            for (int i = 0; i < m.size(); ++i) {
                if (m[i]) {
                    tmp.push_back(i);
                    --m[i];
                    --size;
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
