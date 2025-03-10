class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        long long mid = (n * 2) - 1;
        return (1 + (mid - 2)) * (n - 1) + mid;
    }
};
