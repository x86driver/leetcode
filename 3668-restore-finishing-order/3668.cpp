class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        set<int> s;
        for (int f : friends) {
            s.insert(f);
        }
        vector<int> ans;
        ans.reserve(friends.size());
        for (int n : order) {
            if (s.find(n) != s.end()) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};
