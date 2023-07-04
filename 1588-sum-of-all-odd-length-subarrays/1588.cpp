class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int length = 1;
        int sum = 0;
        while (length <= arr.size()) {
            for (int i = 0; i < arr.size(); ++i) {
                if (i + length > arr.size())
                    break;
                for (int j = i; j < i + length; ++j) {
                    sum += arr[j];
                }
            }
            length += 2;
        }
        return sum;
    }
};
