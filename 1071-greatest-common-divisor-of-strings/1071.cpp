class Solution {
private:
    int gcd(int a, int b, int d) {
        if (b == 0) {
            return a;
        }
        return ::gcd(b, a % b);
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if ((str1 + str2) != (str2 + str1)) {
            return "";
        }
        string sub = str1.substr(0, ::gcd(str1.size(), str2.size()));
        return sub;
    }
};
