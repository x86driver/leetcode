class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for (const vector<string>& path : paths) {
            m[path[0]] = path[1];
        }

        string& prev = paths[0][0];
        string next;
        while (true) {
            next = m[prev];
            if (next.empty())
                return prev;
            prev = m[next];
            if (prev.empty())
                return next;
        }
        return prev;
    }
};
