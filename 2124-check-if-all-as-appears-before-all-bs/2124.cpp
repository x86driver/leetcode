class Solution {
public:
    bool checkString(string s) {
        bool start_b = false;
        for (char c : s) {
            if (c == 'b')
                start_b = true;
            if (c == 'a' && start_b)
                return false;
        }
        return true;
    }
};
