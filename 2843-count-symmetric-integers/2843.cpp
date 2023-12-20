class Solution {
private:
    bool isSymmetric(int val) {
        vector<int> n;
        int tmp = val;
        while (tmp) {
            n.push_back(tmp % 10);
            tmp /= 10;
        }
        if (n.size() % 2 != 0)
            return false;
        int sum = 0;
        for (int i = 0; i < n.size() / 2; ++i)
            sum += n[i];
        for (int i = n.size() / 2; i < n.size(); ++i)
            sum -= n[i];
        return sum == 0;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            if (isSymmetric(i)) {
                ++count;
            }
        }
        return count;
    }
};
