class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int value = 0;
        for (const string& op : operations) {
            if (op[0] == '+' || op[2] == '+') {
                ++value;
            } else {
                --value;
            }
        }
        return value;
    }
};
