class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; ++i) {
            pair<int, int> p = pq.top();
            p.first *= multiplier;
            pq.pop();
            pq.push(p);
        }

        while (!pq.empty()) {
            const pair<int, int> &p = pq.top();
            nums[p.second] = p.first;
            pq.pop();
        }
        return nums;
    }
};
