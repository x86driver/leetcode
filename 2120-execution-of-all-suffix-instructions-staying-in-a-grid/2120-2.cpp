class Solution {
private:
    int solve(int n, vector<int> startPos, const string& sub) {
        int count = 0;
        for (char c : sub) {
            switch (c) {
                case 'R': ++startPos[1]; break;
                case 'L': --startPos[1]; break;
                case 'D': ++startPos[0]; break;
                case 'U': --startPos[0]; break;
            }
            if (startPos[0] < 0 || startPos[0] >= n || startPos[1] < 0 || startPos[1] >= n) {
                return count;
            }
            ++count;
        }
        return count;
    }
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        ans.reserve(s.size());
        for (int i = 0; i < s.size(); ++i) {
            ans.push_back(solve(n, startPos, s.substr(i)));
        }
        return ans;
    }
};
