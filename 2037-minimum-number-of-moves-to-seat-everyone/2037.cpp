class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int sum = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for (int i = 0; i < seats.size(); ++i) {
            int start = students[i];
            int end = seats[i];
            int moves = abs(start - end);
            sum += moves;
        }
        return sum;
    }
};
