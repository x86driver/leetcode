class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int n : nums)
            s.insert(n);
        priority_queue<int> pq;
        for (int n : s)
            pq.push(n);

        int ans = pq.top();
        for (int i = 0; i < 2; ++i) {
            if (pq.empty())
                break;
            pq.pop();
        }
        if (!pq.empty())
            ans = pq.top();
        return ans;
    }
};
