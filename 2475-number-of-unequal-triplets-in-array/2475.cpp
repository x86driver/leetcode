struct Triple {
    int a;
    int b;
    int c;
    bool operator<(const struct Triple& r) const {
        if (a != r.a)
            return a < r.a;
        if (b != r.b)
            return b < r.b;
        return c < r.c;
    }
};

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count = 0;
        set<Triple> triple;
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
