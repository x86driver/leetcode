class Solution {
private:
    int reverseDigits(int num) {
        int ans = 0;
        while (num > 0) {
            ans = ans * 10 + (num % 10);
            num /= 10;
        }
        return ans;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for (int n : nums) {
            s.insert(n);
            s.insert(reverseDigits(n));
        }
        return s.size();
    }
};
