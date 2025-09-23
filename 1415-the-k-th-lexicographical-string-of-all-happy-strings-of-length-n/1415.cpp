class Solution {
private:
    string temp;
    string ans;
    int count;
    void bt(int index, int n, int k) {
        if (count == k) {
            return;
        }
        if (index >= n) {
            if (temp.size() == n) {
                ++count;
                if (count == k) {
                    ans = temp;
                }
            }
            return;
        }
        for (char c = 'a'; c <= 'c'; ++c) {
            if (temp.empty() || (!temp.empty() && temp.back() != c)) {
                temp += c;
                bt(index + 1, n, k);
                temp.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        count = 0;
        bt(0, n, k);
        return ans;
    }
};
