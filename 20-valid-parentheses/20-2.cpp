class Solution {
public:
    bool isValid(string s) {
        map<char, char> m = {{'(', ')'},
                             {'{', '}'},
                             {'[', ']'}};

        stack<char> st;
        for (char c : s) {
            if (m.find(c) != m.end()) {
                st.push(c);
            } else {
                if (st.empty())
                    return false;
                char top = st.top();
                if (m.find(top) == m.end())
                    return false;
                else if (m[top] != c)
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
