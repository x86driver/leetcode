class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int head = 0;
        int tail = 1;
        while (head < s.size()) {
            int start = head;
            while (tail < s.size()) {
                if (s[head] == s[tail]) {
                    ++tail;
                    continue;
                } else {
                    break;
                }
            }
            if ((tail - start) >= 3) {
                vector<int> interval;
                interval.push_back(start);
                interval.push_back(tail - 1);
                ans.push_back(interval);
            }
            head = tail;
            tail = head + 1;
        }

        return ans;
    }
};
