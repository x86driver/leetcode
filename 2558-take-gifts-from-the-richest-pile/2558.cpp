class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int n : gifts) {
            pq.push(n);
        }

        for (int i = 0; i < k; ++i) {
            int val = pq.top();
            pq.pop();
            pq.push(sqrt(val));
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
