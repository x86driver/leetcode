class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for (string& token : tokens) {
            int val = 0;
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                s.push(token);
            } else {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                if (token == "+")
                    val = b + a;
                else if (token == "-")
                    val = b - a;
                else if (token == "*")
                    val = b * a;
                else if (token == "/")
                    val = a == 0 ? 0 : b / a;
                s.push(to_string(val));
            }
        }

        return stoi(s.top());
    }
};
