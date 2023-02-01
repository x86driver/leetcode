class Solution {
private:
    bool isValid(vector<int>& piles, int h, int k) {
        for (int pile : piles) {
            int eatTime = pile / k;
            if (pile % k != 0)
                ++eatTime;
            h -= eatTime;
        }

        return h >= 0;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int pile : piles)
            right = max(right, pile);

        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(piles, h, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
};
