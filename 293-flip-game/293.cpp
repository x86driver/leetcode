class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        for (int i = 1; i < currentState.size(); ++i) {
            string tmp = currentState;
            if (tmp[i - 1] == '+' && tmp[i] == '+') {
                tmp[i - 1] = '-';
                tmp[i] = '-';
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
