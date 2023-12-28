class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        uint32_t exp = 1;
        while (num) {
            int bit = ((num % 2) == 0);
            result += bit * exp;
            exp *= 2;
            num >>= 1;
        }
        return result;
    }
};
