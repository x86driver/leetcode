class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0;
        int zero = 0;
        bool cur_one = false;
        int local_one = 0;
        int local_zero = 0;
        for (char c : s) {
            if (c == '0') {
                if (cur_one) {
                    cur_one = false;
                    one = max(one, local_one);
                    local_one = 0;
                }
                ++local_zero;
            } else { // c == '1'
                if (!cur_one) {
                    cur_one = true;
                    zero = max(zero, local_zero);
                    local_zero = 0;
                }
                ++local_one;
            }
        }
        one = max(one, local_one);
        zero = max(zero, local_zero);
        return one > zero;
    }
};
