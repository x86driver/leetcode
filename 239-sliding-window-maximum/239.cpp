class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int> q;
        unordered_map<int, int> deleted;

        for (int i = 0; i < k - 1; ++i)
            q.push(nums[i]);

        for (int i = k - 1; i < nums.size(); ++i) {
            q.push(nums[i]);

            while (!q.empty()) {
                int top = q.top();
                if (deleted.find(top) != deleted.end()) {
                    --deleted[top];
                    if (deleted[top] == 0)
                        deleted.erase(top);
                    q.pop();
                } else {
                    break;
                }
            }
            ans.push_back(q.top());
            deleted[nums[i - k + 1]]++;
        }

        return ans;
    }
};
