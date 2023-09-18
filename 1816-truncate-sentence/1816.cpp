class Solution {
public:
    string truncateSentence(string s, int k) {
        istringstream iss(s);
        string ans;
        string token;

        while (iss >> token) {
            ans += token;
            --k;
            if (k == 0)
                break;
            ans += " ";
        }

        return ans;
    }
};
