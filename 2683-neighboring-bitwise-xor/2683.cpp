class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int last = 0;
        for (int n : derived) {
            last ^= n;
        }
        return last == 0;
    }
};
