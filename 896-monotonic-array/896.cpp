class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        stack<int> s;
        for (int n : nums) {
            while (!s.empty() && s.top() < n)
                s.pop();
            s.push(n);
        }

        stack<int> s2;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int n = nums[i];
            while (!s2.empty() && s2.top() < n)
                s2.pop();
            s2.push(n);
        }

        return s.size() == nums.size() || s2.size() == nums.size();
    }
};
