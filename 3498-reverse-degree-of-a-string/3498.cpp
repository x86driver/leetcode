class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            int index = s[i] - 'a' + 1;
            int rev = 27 - index;
            int product = rev * (i + 1);
            sum += product;
        }
        return sum;
    }
};
