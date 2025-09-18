class Solution {
private:
    vector<string> ans;
    string curr;
    int n;
    void bt(int index) {
        if (curr.size() >= n) {
            ans.push_back(curr);
            return;
        }
        if (curr.empty() || (!curr.empty() && curr.back() == '1')) {
            curr += '0';
            bt(index + 1);
            curr.pop_back();
        }

        curr += '1';
        bt(index + 1);
        curr.pop_back();
    }
public:
    vector<string> validStrings(int n) {
        this->n = n;
        bt(0);
        return ans;
    }
};
