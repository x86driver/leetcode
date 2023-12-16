class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for (int i = 0; i < strs[0].size(); ++i) {
            char prev = strs[0][i];
            bool sorted = true;
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] < prev) {
                    sorted = false;
                    break;
                }
                prev = strs[j][i];
            }
            if (!sorted)
                ++count;
        }
        return count;
    }
};
