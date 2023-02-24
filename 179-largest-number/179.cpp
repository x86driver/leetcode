class Solution {
private:
    struct greater {
        bool operator()(int a, int b) const {
            // a: 901
            // b: 1002
            string stra = to_string(a);
            string strb = to_string(b);
            return stol(stra + strb) > stol(strb + stra);
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater());
        string ret;
        size_t i = 0;
        for (; i < nums.size(); ++i)
            if (nums[i] != 0)
                break;

        for (; i < nums.size(); ++i)
            ret += to_string(nums[i]);

        if (ret.size() == 0)
            return "0";
        return ret;
    }
};
