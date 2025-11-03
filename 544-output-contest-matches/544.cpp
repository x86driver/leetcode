class Solution {
public:
    string findContestMatch(int n) {
        string ans;
        vector<string> pairing;
        for (int i = 1; i <= n; ++i) {
            string tmp = to_string(i);
            pairing.push_back(tmp);
        }


        for (int i = 1; i <= n; i *= 2) {
            int start = 0;
            int end = (n - 1) / i;
            while (start < end) {
                pairing[start] = "(" + pairing[start] + "," + pairing[end] + ")";
                ++start;
                --end;
            }
        }

        return pairing[0];
    }
};
