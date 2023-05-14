class Solution {
public:
    string reformatDate(string date) {
        string month[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string ret = date.substr(date.size() - 4);
        ret += "-";
        string mon = date.substr(date.size() - 8, 3);
        for (int i = 1; i < sizeof(month) / sizeof(month[1]); ++i) {
            if (mon == month[i]) {
                if (i < 10)
                    ret += "0";
                ret += to_string(i);
            }
        }
        ret += "-";
        string day;
        for (int i = 0; i < date.size(); ++i) {
            if (isdigit(date[i]))
                day += date[i];
            else
                break;
        }

        if (day.size() == 1)
            ret += "0";
        ret += day;
        return ret;
    }
};
