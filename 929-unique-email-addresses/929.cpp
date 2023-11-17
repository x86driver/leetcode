class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (const string& str : emails) {
            string email;
            bool skip = false;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == '@') {
                    email += str.substr(i);
                    break;
                } else if (skip) {
                    continue;
                } if (str[i] == '.') {
                    continue;
                } else if (str[i] == '+') {
                    skip = true;
                    continue;
                }
                email += str[i];
            }
            s.insert(email);
        }

        return s.size();
    }
};
