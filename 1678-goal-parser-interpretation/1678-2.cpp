class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                ans += 'G';
                continue;
            }
            if (command[i + 1] == 'a') {
                ans += "al";
                i += 3;
                continue;
            } else {
                ans += 'o';
                i += 1;
                continue;
            }
        }
        return ans;
    }
};
