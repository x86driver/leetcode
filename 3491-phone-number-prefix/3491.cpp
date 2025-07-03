class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size() - 1; ++i) {
            int len = min(numbers[i].size(), numbers[i + 1].size());
            int match = 0;
            for (int j = 0; j < len; ++j) {
                if (numbers[i][j] == numbers[i + 1][j]) {
                    ++match;
                } else {
                    break;
                }
            }
            if (match == len) {
                return false;
            }
        }
        return true;
    }
};
