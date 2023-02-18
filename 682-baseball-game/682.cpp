class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string op : operations) {
            if (op == "C") {
                st.pop();
            } else if (op == "D") {
                int top = st.top();
                st.push(top * 2);
            } else if (op == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a + b);
            } else {
                st.push(stoi(op));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
