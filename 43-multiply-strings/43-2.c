#define max(a,b) (((a) > (b)) ? (a) : (b))

char * multiply(char * num1, char * num2){
    if (num1[0] == '0' || num2[0] == '0') {
        char *ans = (char*)calloc(2, sizeof(char));
        ans[0] = '0';
        ans[1] = '\0';
        return ans;
    }

    int num1_digit[200] = {0};
    int num2_digit[200] = {0};
    int result[400] = {0};
    int digit = 0;

    for (int i = 0; i < strlen(num2); ++i) {
        int x = num2[strlen(num2) - i - 1] - '0';
        int carry = 0;
        for (int j = 0; j < strlen(num1); ++j) {
            int y = num1[strlen(num1) - j - 1] - '0';
            int product = x * y + carry;
            if (product >= 10) {
                result[i+j] += product % 10;
                carry = (int)(product / 10);
            } else {
                result[i+j] += product;
                carry = 0;
            }
            if (result[i+j] >= 10) {
                carry += (int)(result[i+j] / 10);
                result[i+j] %= 10;
            }
            digit = max(digit, i+j);
        }
        if (carry) {
            result[i+strlen(num1)] += carry;
            digit = max(digit, i+strlen(num1));
        }
    }

    char *ans = (char*)calloc(digit+2, sizeof(char));
    for (int i = digit; i >= 0; --i) {
        ans[digit-i] = result[i] + '0';
    }
    ans[digit+1] = '\0';

    return ans;
}
