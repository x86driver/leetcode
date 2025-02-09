class Solution {
public:
    bool isBalanced(string num) {
        int result[2] = {0, 0};
        for (int i = 0; i < num.size(); ++i) {
            int n = num[i] - '0';
            result[i % 2] += n;
        }
        return result[0] == result[1];
    }
};
