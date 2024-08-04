class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void bt(int n, int k, int index) {
        if (tmp.size() >= k) {
            ans.push_back(tmp);
            return;
        } else if (index > n) {
            return;
        }
        bt(n, k, index + 1);

        tmp.push_back(index);
        bt(n, k, index + 1);
        tmp.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        bt(n, k, 1);
        return ans;
    }
};
