class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int count = 0;
        set<int> s;
        for (int n : nums) {
            s.insert(n);
            int rev = 0;
            while (n) {
                rev *= 10;
                rev += n % 10;
                n /= 10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};
