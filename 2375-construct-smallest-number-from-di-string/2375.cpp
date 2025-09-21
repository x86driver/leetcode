class Solution {
private:
    string ans;
    string temp;
    vector<bool> used;
    bool found;
    void bt(const string& pattern, int index) {
        if (found) {
            return;
        }
        if (index >= pattern.size()) {
            if (temp.size() == pattern.size() + 1) {
                ans = temp;
                found = true;
                return;
            }
            return;
        }
        for (int i = 0; i < used.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                if (temp.empty()) {
                    temp += (i + 1) + '0';
                    bt(pattern, index);
                    temp.pop_back();
                } else if (pattern[index] == 'I') {
                    int last = temp.back() - '0';
                    if ((i + 1) > last) {
                        temp += (i + 1) + '0';
                        bt(pattern, index + 1);
                        temp.pop_back();
                    }
                } else if (pattern[index] == 'D') {
                    int last = temp.back() - '0';
                    if ((i + 1) < last) {
                        temp += (i + 1) + '0';
                        bt(pattern, index + 1);
                        temp.pop_back();
                    }
                }
                used[i] = false;
            }
        }
    }
public:
    string smallestNumber(string pattern) {
        found = false;
        used.resize(9);
        bt(pattern, 0);
        return ans;
    }
};
