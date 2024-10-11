/**
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            int num = pow(2, i);
            if (commonSetBits(num)) {
                int tmp = 1 << i;
                ans |= tmp;
            }
        }
        return ans;
    }
};
