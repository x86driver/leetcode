class Solution {
public:
    int minOperations(int n) {
        int h = n / 2;
        int a = n - 1; // i == 0
        int half = h - 1;
        int b = n - (2 * half + 1);
        int ans = (a + b) * h / 2;
        return ans;
    }
};
