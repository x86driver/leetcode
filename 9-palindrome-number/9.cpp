class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        vector<int> arr;
        while (x > 0) {
            arr.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < arr.size() / 2; ++i) {
            if (arr[i] != arr[arr.size() - i - 1]) {
                return false;
            }
        }

        return true;
    }
};
