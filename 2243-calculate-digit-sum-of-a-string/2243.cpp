class Solution {
public:
    string digitSum(string s, int k) {
        string new_str = s;
        while (s.size() > k) {
            int start = 0;
            new_str = "";
            while (start < s.size()) {
                string sub = s.substr(start, k);
                start += k;
                int sum = 0;
                for (char c : sub) {
                    sum += c - '0';
                }
                new_str += to_string(sum);
            }
            s = new_str;
        }
        return s;
    }
};
