class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s;
        for (int n : nums)
            s.insert(n);
        while (s.find(original) != s.end()) {
            original *= 2;
        }
        return original;

    }
};
