class Solution {
public:
    int totalMoney(int n) {
        int money = 0;
        int start = 1;
        int week = n / 7;
        money += ((28 + 7 * (week + 3)) * week) / 2;
        int day = n % 7;
        money += (week + 1 + (week + 1 + (day - 1))) * day / 2;
        return money;
    }
};
