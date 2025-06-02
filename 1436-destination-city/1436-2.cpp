class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for (const vector<string>& path : paths) {
            m[path[0]] = path[1];
        }
        string start = paths[0][0];
        while (m.find(start) != m.end()) {
            start = m[start];
        }
        return start;
    }
};
