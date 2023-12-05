class Solution {
public:
    string largestGoodInteger(string num) {
        int maximum = -1;
        string ans;
        for (int i = 0; i <= num.size() - 3; ++i) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                string sub = num.substr(i, 3);
                int val = stoi(sub);
                if (val > maximum) {
                    maximum = val;
                    ans = sub;
                }
            }
        }
        return ans;
    }
};
