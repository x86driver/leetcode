class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, set<char>> rods;
        for (int n = 0; n <= 9; ++n) {
            rods[n] = set<char>();
        }

        size_t i = 0;
        while (i < rings.size() - 1) {
            rods[rings[i + 1] - '0'].insert(rings[i]);
            i += 2;
        }

        int ans = 0;
        for (auto &it : rods)
            if (it.second.size() == 3)
                ++ans;

        return ans;
    }
};
