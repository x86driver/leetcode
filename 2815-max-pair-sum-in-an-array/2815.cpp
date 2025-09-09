class Solution {
private:
    int largest_digit(int num) {
        int ret = 0;
        while (num) {
            ret = max(ret, num % 10);
            num /= 10;
        }
        return ret;
    }
public:
    int maxSum(vector<int>& nums) {
        vector<priority_queue<int>> vec_pq(10);
        for (int n : nums) {
            int digit = largest_digit(n);
            vec_pq[digit].push(n);
        }
        int ans = -1;
        for (priority_queue<int>& pq : vec_pq) {
            if (pq.size() < 2) {
                continue;
            }
            int sum = pq.top();
            pq.pop();
            sum += pq.top();
            ans = max(ans, sum);
        }
        return ans;
    }
};
