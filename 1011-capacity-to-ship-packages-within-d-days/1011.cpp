class Solution {
private:
    bool isValid(vector<int>& weights, int days, int capacity) {
        int loading = 0;
        --days;
        for (int w : weights) {
            if (loading + w <= capacity) {
                loading += w;
            } else if (w > capacity) {
                return false;
            } else {
                loading = w;
                --days;
            }
        }

        return days >= 0;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MAX;
        int right = 0;
        int sum = 0;
        for (int w : weights) {
            left = min(left, w);
            sum += w;
        }

        right = sum + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(weights, days, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
};
