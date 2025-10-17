class Solution {
private:
    vector<int> temp;
    int sum;
    vector<int> pow_table;
    inline int three_pow(int y) {
        return pow_table[y];
    }
    bool bt(const int n, int index) {
        if (index >= pow_table.size()) {
            // for (int x : temp) {
            //     cout << x << " ";
            // }
            // cout << ", sum: " << sum << endl;
            return false;
        }

        sum += three_pow(index);
        if (sum > n) {
            // cout << sum << ", sum > n" << endl;
            sum -= three_pow(index);
            return false;
        } else if (sum == n) {
            // cout << sum << ", sum == n" << endl;
            sum -= three_pow(index);
            return true;
        }
        temp.push_back(index);
        if (bt(n, index + 1)) {
            temp.pop_back();
            sum -= three_pow(index);
            return true;
        }
        temp.pop_back();
        sum -= three_pow(index);

        if (bt(n, index + 1)) {
            return true;
        }

        return false;
    }
public:
    bool checkPowersOfThree(int n) {
        // n = 0~15
        sum = 0;
        pow_table.resize(16);
        for (int i = 0; i < pow_table.size(); ++i) {
            pow_table[i] = pow(3, i);
        }
        return bt(n, 0);
    }
};
