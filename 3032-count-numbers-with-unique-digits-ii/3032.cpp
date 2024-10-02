class Solution {
private:
    bool isUnique(int v) {
        vector<int> m(10);
        while (v) {
            ++m[v % 10];
            v /= 10;
        }
        for (int x : m) {
            if (x > 1)
                return false;
        }
        return true;
    }
public:
    int numberCount(int a, int b) {
        int count = 0;
        for (int i = a; i <= b; ++i) {
            if (isUnique(i))
                ++count;
        }
        return count;
    }
};
