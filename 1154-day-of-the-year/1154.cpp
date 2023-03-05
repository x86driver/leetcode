class Solution {
private:
    bool isLeapYear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        else
            return false;
    }
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 7));
        int day = stoi(date.substr(8, 10));

        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeapYear(year))
            days[1] = 29;

        for (int i = 0; i < month - 1; ++i)
            day += days[i];

        return day;
    }
};
