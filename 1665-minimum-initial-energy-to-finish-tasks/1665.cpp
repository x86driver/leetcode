class Solution {
private:
    bool isValid(vector<vector<int>>& tasks, int energy) {
        for (vector<int>& task : tasks) {
            if (energy >= task[1])
                energy -= task[0];
            else
                return false;
        }
        return true;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[0] - a[1]) < (b[0] - b[1]);
             });
        int left = 0;
        int right = 0;
        for (vector<int>& task : tasks) {
            left += task[0];
            right += task[1];
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(tasks, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
};
