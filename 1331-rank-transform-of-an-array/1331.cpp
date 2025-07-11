class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return {};
        }
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        map<int, int> unique;

        int rank = 0;
        int prev = 0;
        int curr = 0;
        unique[sorted[0]] = 0;
        for (int i = 1; i < sorted.size(); ++i) {
            prev = curr;
            curr = i;
            if (sorted[prev] != sorted[curr]) {
                unique[sorted[curr]] = ++rank;
            }
        }

        vector<int> ans;
        ans.reserve(arr.size());

        for (int i = 0; i < arr.size(); ++i) {
            int target = arr[i];
            ans.push_back(unique[target] + 1);
        }
        return ans;
    }
};
