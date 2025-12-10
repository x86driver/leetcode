class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int n : nums) {
            s.insert(n);
        }
        int div = k;
        while (div <= 200) {
            if (s.find(div) == s.end()) {
                return div;
            }
            div += k;
        }
        return 1;
    }
};
