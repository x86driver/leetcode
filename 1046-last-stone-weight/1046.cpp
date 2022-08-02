class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < stones.size(); ++i) {
            q.push(make_pair(stones[i], i));
        }

        while (!q.empty()) {
            int max = q.top().first;
            int max_pos = q.top().second;
            q.pop();

            if (q.empty()) {
                return max;
            }

            int second = q.top().first;
            int second_pos = q.top().second;
            q.pop();

            stones[second_pos] = 0;
            stones[max_pos] = max - second;

            q.push(make_pair(stones[max_pos], max_pos));
        }

        return 0;
    }
};
