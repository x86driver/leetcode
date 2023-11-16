class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int count = 0;
        sort(weight.begin(), weight.end());
        int w = 5000;
        for (int i = 0; i < weight.size(); ++i) {
            if (weight[i] <= w) {
                w -= weight[i];
                ++count;
            } else {
                break;
            }
        }
        return count;
    }
};
