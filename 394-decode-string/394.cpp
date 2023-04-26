class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (char c : s) {
            if (c != ']') {
                st.push(c);
                continue;
            } else {
                string decodedString;
                while (st.top() != '[') {
                    decodedString.insert(0, 1, st.top());
                    st.pop();
                }
                st.pop();
                string n;
                while (!st.empty()) {
                    if (st.top() < '0' || st.top() > '9')
                        break;
                    n.insert(0, 1, st.top());
                    st.pop();
                }
                int k = stoi(n);
                string multiple;
                for (int i = 0; i < k; ++i)
                    multiple += decodedString;
                for (char d : multiple)
                    st.push(d);
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
