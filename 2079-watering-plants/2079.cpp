class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int i = 0;
        int rest = 0;
        while (i < plants.size()) {
            if (rest < 0) {
                rest = capacity;
                steps += i + 1;
            } else {
                ++steps;
            }
            rest = rest - plants[i];
            if (rest < 0) {
                steps += i - 1;
                continue;
            }
            ++i;
        }
        return steps;
    }
};
