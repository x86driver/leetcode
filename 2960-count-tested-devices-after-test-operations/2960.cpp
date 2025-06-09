class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int timer = 0;
        int count = 0;
        for (int battery : batteryPercentages) {
            battery -= timer;
            if (battery > 0) {
                ++count;
                ++timer;
            }
        }
        return count;
    }
};
