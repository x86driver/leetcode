class Solution {
private:
    set<int> s;
    vector<int> temp;
    vector<bool> used;
    int count;
    void bt(const vector<int>& digits, int n) {
        if (n >= digits.size() || temp.size() >= 3) {
            if (temp.size() == 3) {
                int num = temp[0] * 100 + temp[1] * 10 + temp[2];
                if (num >= 100 && (num % 2) == 0) {
                    s.insert(num);
                }
            }
            return;
        }
        for (int i = 0; i < used.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                temp.push_back(digits[i]);
                bt(digits, n + 1);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
public:
    int totalNumbers(vector<int>& digits) {
        used.resize(digits.size());
        count = 0;
        bt(digits, 0);
        return s.size();
    }
};
