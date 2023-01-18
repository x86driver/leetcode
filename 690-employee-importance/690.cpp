/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int max_id = 0;
        unordered_map<int, Employee*> m;
        for (Employee *e : employees) {
            m[e->id] = e;
            max_id = max(max_id, e->id);
        }

        int importance = 0;
        vector<int> visit(max_id+1);
        queue<int> q;

        q.push(id);
        visit[id] = true;
        importance += m[id]->importance;

        while (!q.empty()) {
            Employee *e = m[q.front()];
            q.pop();

            for (int sub : e->subordinates) {
                if (!visit[sub]) {
                    q.push(sub);
                    visit[sub] = true;
                    importance += m[sub]->importance;
                }
            }
        }

        return importance;
    }
};
