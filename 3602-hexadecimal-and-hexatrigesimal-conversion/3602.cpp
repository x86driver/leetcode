class Solution {
public:
    string concatHex36(int n) {
        int n2 = n * n;
        int n3 = n2 * n;
        string base16, base36;
        while (n2) {
            int x = n2 % 16;
            if (x < 10) {
                base16 += (x + '0');
            } else {
                base16 += ((x - 10) + 'A');
            }
            n2 /= 16;
        }

        while (n3) {
            int x = n3 % 36;
            if (x < 10) {
                base36 += (x + '0');
            } else {
                base36 += ((x - 10) + 'A');
            }
            n3 /= 36;
        }

        reverse(base16.begin(), base16.end());
        reverse(base36.begin(), base36.end());

        return base16 + base36;
    }
};
