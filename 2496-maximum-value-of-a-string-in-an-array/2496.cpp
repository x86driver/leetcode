class Solution {
private:
    int length(const string& str) {
        bool isnumeric = true;
        for (char c : str) {
            if (c < '0' || c > '9') {
                isnumeric = false;
                break;
            }
        }
        if (isnumeric)
            return stoi(str);
        else
            return str.size();
    }
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (const string& str : strs) {
            ans = max(ans, length(str));
        }
        return ans;
    }
};
