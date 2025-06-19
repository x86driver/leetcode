class Solution {
public:
    int countOddLetters(int n) {
        const string words[] = {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
        };
        map<char, int> m;
        while (n) {
            const string &str = words[n % 10];
            for (char c : str) {
                ++m[c];
            }
            n /= 10;
        }
        int count = 0;
        for (auto &it : m) {
            if (it.second % 2 == 1) {
                ++count;
            }
        }
        return count;
    }
};
