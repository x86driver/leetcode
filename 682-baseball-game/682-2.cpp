class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (const string& op : operations) {
            if (op == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a + b);
            } else if (op == "C") {
                st.pop();
            } else if (op == "D") {
                int a = st.top();
                st.push(2 * a);
            } else {
                int val = stoi(op);
                st.push(val);
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
