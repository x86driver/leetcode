class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int answer = 0;
        set<char> s;

        for (char j : jewels) {
            s.insert(j);
        }

        for (char stone : stones) {
            if (s.find(stone) != s.end()) {
                ++answer;
            }
        }

        return answer;
    }
};
