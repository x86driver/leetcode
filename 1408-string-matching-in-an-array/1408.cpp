class Solution {
private:
    string isSubstr(const string& str1, const string& str2) {
        string a = str1;
        string b = str2;
        if (a.size() > b.size()) {
            swap(a, b);
        }
        for (int i = 0; i < b.size(); ++i) {
            bool found = true;
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] != b[i + j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return a;
            }
        }
        return "";
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> s;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                string sub = isSubstr(words[i], words[j]);
                if (sub.size() > 0) {
                    s.insert(sub);
                }
            }
        }
        for (const string& str : s) {
            ans.push_back(str);
        }
        return ans;
    }
};
