class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<bool> used;
    void bt(int index, int n) {
        if (index >= n) {
            if (temp.size() == n) {
                ans.push_back(temp);
            }
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                used[i] = true;
                int curr = i + 1;
                int last = temp.empty() ? curr + 1 : temp.back();
                if ((curr % 2 == 0 && last % 2 == 0) || (curr % 2 == 1 && last % 2 == 1)) {
                    bt(index + 1, n);
                } else {
                    temp.push_back(i + 1);
                    bt(index + 1, n);
                    temp.pop_back();
                }
                used[i] = false;
            }
        }

    }
public:
    vector<vector<int>> permute(int n) {
        used.resize(n);
        bt(0, n);
        return ans;
    }
};
