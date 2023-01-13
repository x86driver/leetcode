class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        stack<double> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() <= cars[i].second) st.pop();
            st.push(cars[i].second);
        }
        return st.size();
    }
};
