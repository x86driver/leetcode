class Solution {
private:
    string toBinary(const string& s) {
        int value = stoi(s);
        string ret;
        while (value) {
            if ((value % 2) == 1)
                ret += '1';
            else
                ret += '0';
            value /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
public:
    string convertDateToBinary(string date) {
        vector<string> tokens;
        stringstream ss(date);
        string token;
        while (getline(ss, token, '-')) {
            tokens.push_back(token);
        }

        string ans;
        for (string &s : tokens) {
            ans += toBinary(s);
            ans += '-';
        }
        ans.pop_back();
        return ans;
    }
};
