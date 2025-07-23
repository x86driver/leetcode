class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int apples = 0;
        for (int a : apple) {
            apples += a;
        }
        int count = 0;
        for (int cap : capacity) {
            apples -= cap;
            ++count;
            if (apples <= 0) {
                break;
            }
        }
        return count;
    }
};
