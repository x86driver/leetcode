class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        unordered_map<int, set<int>> m;
        int ans = 0;
        for (const vector<int>& student : students) {
            m[student[1]].insert(student[0]);
            ans = max(ans, (int)m[student[1]].size());
        }
        return ans;
    }
};
