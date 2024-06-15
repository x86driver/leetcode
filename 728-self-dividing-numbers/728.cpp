class Solution {
private:
    bool isSelfDividing(int num) {
        const int origin = num;
        while (num) {
            int m = num % 10;
            if (m == 0)
                return false;
            if ((origin % m) != 0)
                return false;
            num /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i)
            if (isSelfDividing(i))
                ans.push_back(i);

        return ans;
    }
};
