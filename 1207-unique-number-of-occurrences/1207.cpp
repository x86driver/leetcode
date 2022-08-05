class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int n : arr) {
            if (m.find(n) == m.end()) {
                m[n] = 1;
            } else {
                ++m[n];
            }
        }

        unordered_map<int, int> rev_map;
        for (auto &n : m) {
            if (rev_map.find(n.second) == rev_map.end()) {
                rev_map[n.second] = n.first;
            } else {
                return false;
            }
        }

        return true;
    }
};
