class Solution {
private:
    int onebits(int n) {
        int count = 0;
        while (n) {
            count += n % 2;
            n /= 2;
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](const int &a, const int &b) {
            int bitsa = onebits(a);
            int bitsb = onebits(b);
            if (bitsa < bitsb) {
                return true;
            } else if (bitsa == bitsb) {
                return a < b;
            } else {
                return false;
            }
        });
        return arr;
    }
};
