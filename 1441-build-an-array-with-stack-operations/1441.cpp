class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int counter = 1;
        for (int t : target) {
            while (counter < t) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++counter;
            }
            if (counter == t) {
                ans.push_back("Push");
                ++counter;
            }
        }
        return ans;
    }
};
