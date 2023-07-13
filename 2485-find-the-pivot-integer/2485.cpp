class Solution {
private:
    int pivotcmp(int x, int n) {
        int sum1 = (1 + x) * x / 2;
        int sum2 = (x + n) * (n - x + 1) / 2;
        return sum1 - sum2;
    }
public:
    int pivotInteger(int n) {
        int left = -1;
        int right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int result = pivotcmp(mid, n);
            if (result == 0)
                return mid;
            if (result < 0)
                left = mid;
            else
                right = mid - 1;
        }

        if (pivotcmp(right, n) == 0)
            return right;
        else
            return -1;
    }
};
