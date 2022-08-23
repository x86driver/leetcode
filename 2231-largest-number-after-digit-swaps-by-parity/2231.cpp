class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd;
        priority_queue<int> even;
        vector<int> array;

        while (num > 0) {
            array.push_back(num % 10);
            num /= 10;
        }
        std::reverse(array.begin(), array.end());

        for (auto &n : array) {
            if ((n % 2) == 0) {
                even.push(n);
            } else {
                odd.push(n);
            }
        }

        int ret = 0;

        for (int i = 0; i < array.size(); ++i) {
            if ((array[i] % 2) == 0) {
                ret = ret * 10 + even.top();
                even.pop();
            } else {
                ret = ret * 10 + odd.top();
                odd.pop();
            }
        }

        return ret;
    }
};
