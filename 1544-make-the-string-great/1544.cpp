class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty()) {
                char last = st.top();
                if (last != c && tolower(last) == tolower(c)) {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
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
