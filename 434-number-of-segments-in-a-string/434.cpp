class Solution {
public:
    int countSegments(string s) {
        istringstream iss(s);
        int count = 0;
        for (string token; iss >> token;) {
            ++count;
        }
        return count;
    }
};
