class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.size() == 0) {
                    return false;
                }
                if (c == ')') {
                    if (st.top() != '(') {
                        return false;
                    } else {
                        st.pop();
                    }
                } else if (c == '}') {
                    if (st.top() != '{') {
                        return false;
                    } else {
                        st.pop();
                    }
                } else if (c == ']') {
                    if (st.top() != '[') {
                        return false;
                    } else {
                        st.pop();
                    }
                }
            }
        }

        return st.size() == 0;
    }
};
