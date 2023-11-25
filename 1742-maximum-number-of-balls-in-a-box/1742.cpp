class Solution {
private:
    int box(int n) {
        int ret = 0;
        while (n) {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> m(46);
        for (int i = lowLimit; i <= highLimit; ++i) {
            ++m[box(i)];
        }
        return *max_element(m.begin(), m.end());
    }
};
