class Solution {
private:
    vector<int> tmp;
    vector<int> can;
    vector<vector<int>> ans;
    void bt(int index, int target) {
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int i = index; i < can.size(); ++i) {
            int n = can[i];
            if (n <= target) {
                tmp.push_back(n);
                bt(i, target - n);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        can = candidates;
        bt(0, target);

        return ans;
    }
};
