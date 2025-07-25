class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0.0;
        int prev = 0;
        for (int i = 0; i < brackets.size(); ++i) {
            int bracket = min(income, brackets[i][0]) - prev;
            if (bracket <= 0) {
                break;
            }
            double percent = brackets[i][1] / 100.0;
            ans += static_cast<double>(bracket) * percent;
            prev = brackets[i][0];
        }
        return ans;
    }
};
