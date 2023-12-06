class Solution {
private:
    long long combine(int a, int b) {
        vector<int> n;
        while (b) {
            n.push_back(b % 10);
            b /= 10;
        }
        while (a) {
            n.push_back(a % 10);
            a /= 10;
        }
        reverse(n.begin(), n.end());
        long long ans = 0;
        for (int i = 0; i < n.size() - 1; ++i) {
            ans += n[i];
            ans *= 10;
        }
        ans += n.back();
        return ans;
    }
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        long long ans = 0;
        while (i < j) {
            ans += combine(nums[i], nums[j]);
            ++i;
            --j;
        }
        if (i == j)
            ans += nums[i];
        return ans;
    }
};
