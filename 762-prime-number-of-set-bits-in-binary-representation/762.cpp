class Solution {
private:
    vector<bool> prime;
    inline bool isPrime(int num) {
        return prime[num];
    }
    int setbits(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 0x01;
            num >>= 1;
        }
        return count;
    }
public:
    Solution() : prime(33) {
        prime[2] = true;
        prime[3] = true;
        prime[5] = true;
        prime[7] = true;
        prime[11] = true;
        prime[13] = true;
        prime[17] = true;
        prime[19] = true;
        prime[23] = true;
        prime[29] = true;
        prime[31] = true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            int bits = setbits(i);
            count += isPrime(bits);
        }
        return count;
    }
};
