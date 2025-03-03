class Solution {
public:
    int countPoints(string rings) {
        vector<unordered_set<char>> m(101);
        for (int i = 0; i < rings.size() - 1; i += 2) {
            char color = rings[i];
            int pos = rings[i + 1] - '0';
            m[pos].insert(color);
        }
        int ans = 0;
        for (int i = 0; i < m.size(); ++i) {
            if (m[i].size() == 3) {
                ++ans;
            }
        }
        return ans;
    }
};
