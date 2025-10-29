class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        char last = part.back();
        for (char c : s) {
            st.push(c);
            if (st.size() >= part.size()) {
                if (st.top() == last) {
                    string tmp;
                    for (int i = 0; i < part.size(); ++i) {
                        tmp += st.top();
                        st.pop();
                    }
                    reverse(tmp.begin(), tmp.end());
                    if (tmp != part) {
                        for (char t : tmp) {
                            st.push(t);
                        }
                    }
                }
            }
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
