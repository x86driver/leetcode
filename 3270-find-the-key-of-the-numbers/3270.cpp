class Solution {
private:
    static inline vector<int> toArr(int num) {
        vector<int> ret;
        for (int i = 0; i < 4; ++i) {
            ret.push_back(num % 10);
            num /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
public:
    int generateKey(int num1, int num2, int num3) {
        vector<int> n1 = toArr(num1);
        vector<int> n2 = toArr(num2);
        vector<int> n3 = toArr(num3);
        int key = 0;
        key += min(min(n1[0], n2[0]), n3[0]);
        key *= 10;
        key += min(min(n1[1], n2[1]), n3[1]);
        key *= 10;
        key += min(min(n1[2], n2[2]), n3[2]);
        key *= 10;
        key += min(min(n1[3], n2[3]), n3[3]);
        return key;
    }
};
