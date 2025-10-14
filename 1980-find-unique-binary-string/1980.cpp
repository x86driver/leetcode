class Solution {
private:
    string plusOne(const string& str) {
        string ret = str;
        const int len = str.size();
        bool carry = true; // initial +1
        for (int i = len - 1; i >= 0; --i) {
            if (carry) {
                if (ret[i] == '0') {
                    ret[i] = '1';
                    return ret;
                } else {
                    ret[i] = '0';
                }
            } else {
                return ret;
            }
        }
        return ret;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums[0].size();
        string curr;
        for (int i = 0; i < n; ++i) {
            curr += '0';
        }

        set<string> s;
        for (const string& str : nums) {
            s.insert(str);
        }

        for (int i = 0; i < pow(2, n); ++i) {
            if (s.find(curr) == s.end()) {
                return curr;
            }
            curr = plusOne(curr);
        }

        return curr;
    }
};
