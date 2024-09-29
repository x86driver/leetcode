class Solution {
private:
    int hash(const string& s) {
        int sum = 0;
        for (char c : s)
            sum += c - 'a';
        return sum % 26;
    }
public:
    string stringHash(string s, int k) {
        string ans;
        for (int i = 0; i < s.size(); i += k) {
            int h = hash(s.substr(i, k));
            ans += h + 'a';
        }
        return ans;
    }
};
