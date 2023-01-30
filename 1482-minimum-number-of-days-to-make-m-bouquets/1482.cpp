class Solution {
public:
    bool isValid(vector<int>& bloomDay, int m, int k, int day) {
        int flowers = 0;
        for (int bloom : bloomDay) {
            if (day - bloom >= 0) {
                ++flowers;
                if (flowers == k) {
                    flowers = 0;
                    --m;
                }
            } else {
                flowers = 0;
            }
        }
        return m <= 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (unsigned int)m * k)
            return -1;

        int left = bloomDay[0];
        int maximum = bloomDay[0];

        for (int bloom : bloomDay) {
            left = min(left, bloom);
            maximum = max(maximum, bloom);
        }

        int right = maximum + 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid + 1;
        }

        if (right == maximum + 1)
            return -1;
        else
            return right;
    }
};
