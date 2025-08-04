class Solution {
private:
    int toMinutes(const string& t) {
        int ret = 0;
        int hour = stoi(t.substr(0, 2));
        int minute = stoi(t.substr(3, 2));
        ret = hour * 60 + minute;
        return ret;
    }
public:
    int convertTime(string current, string correct) {
        int current_minutes = toMinutes(current);
        int correct_minutes = toMinutes(correct);

        int diff = correct_minutes - current_minutes;
        int ans = 0;
        ans += diff / 60;
        diff %= 60;
        ans += diff / 15;
        diff %= 15;
        ans += diff / 5;
        diff %= 5;
        ans += diff;
        return ans;
    }
};
