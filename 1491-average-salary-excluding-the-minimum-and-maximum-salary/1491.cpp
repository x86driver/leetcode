class Solution {
public:
    double average(vector<int>& salary) {
        uint64_t minimum = UINT64_MAX;
        uint64_t maximum = 0;
        uint64_t total = 0;
        for (int s : salary) {
            minimum = min(minimum, static_cast<uint64_t>(s));
            maximum = max(maximum, static_cast<uint64_t>(s));
            total += s;
        }
        return (total - (minimum + maximum)) / 1.0 / (salary.size() - 2);
    }
};
