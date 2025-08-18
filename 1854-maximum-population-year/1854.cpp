class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(101);
        for (const vector<int>& person : logs) {
            int birth = person[0];
            int death = person[1];
            for (int i = birth; i < death; ++i) {
                ++population[i - 1950];
            }
        }
        int year = -1;
        int maximum = 0;
        for (int i = 0; i < population.size(); ++i) {
            if (population[i] > maximum) {
                maximum = population[i];
                year = i;
            }
        }
        return year + 1950;
    }
};
