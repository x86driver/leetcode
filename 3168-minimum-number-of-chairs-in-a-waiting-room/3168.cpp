class Solution {
public:
    int minimumChairs(string s) {
        stack<char> st;
        int chairs = 0;
        for (char c : s) {
            if (c == 'E') {
                st.push('E');
                chairs = max(chairs, static_cast<int>(st.size()));
            } else {
                st.pop();
            }
        }
        return chairs;
    }
};
