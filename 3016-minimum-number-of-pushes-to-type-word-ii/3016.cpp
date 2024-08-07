class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for (char c : word) {
            ++m[c];
        }
        vector<pair<char, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
            return p1.second > p2.second;
        });

        int count = 0;

        for (int i = 0; i < vec.size(); ++i) {
            int push = i / 8 + 1;
            count += vec[i].second * push;
        }

        return count;

        return 0;
    }
};
