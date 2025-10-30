class Solution {
private:
    vector<int> tmp;
    map<int, int> m;
    void bt(const vector<int>& nums, int index) {
        if (index >= nums.size()) {
            int val = 0;
            for (int n : tmp) {
                val |= n;
            }
            ++m[val];
            return;
        }
        bt(nums, index + 1);

        tmp.push_back(nums[index]);
        bt(nums, index + 1);
        tmp.pop_back();
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        bt(nums, 0);
        auto last = m.end();
        --last;
        return last->second;
    }
};
