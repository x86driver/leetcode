class Solution {
private:
    bool isOdd(int num) {
        return (num % 2) == 1;
    }
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        int count = 0;
        while ((i + 2) < arr.size()) {
            if (isOdd(arr[i]) && isOdd(arr[i+1]) && isOdd(arr[i+2])) {
                return true;
            }
            ++i;
        }

        return false;
    }
};
