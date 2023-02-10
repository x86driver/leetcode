class Solution {
public:
    string nextClosestTime(string time) {
        string hours = string(time.begin(), time.begin() + 2);
        string mins = string(time.begin() + 3, time.begin() + 5);

        set<char> s;
        for (char c : hours)
            s.insert(c);
        for (char c : mins)
            s.insert(c);

        vector<string> all_two_digits;
        for (char a : s)
            for (char b : s)
                all_two_digits.push_back(string() + a + b);

        int i = -1;
        auto it = find(all_two_digits.begin(), all_two_digits.end(), mins);
        if (it != all_two_digits.end())
            i = distance(all_two_digits.begin(), it);

        if ((i + 1) < all_two_digits.size() && stoi(all_two_digits[i + 1]) < 60)
            return hours + ":" + all_two_digits[i + 1];

        i = -1;
        it = find(all_two_digits.begin(), all_two_digits.end(), hours);
        if (it != all_two_digits.end())
            i = distance(all_two_digits.begin(), it);

        if ((i + 1) < all_two_digits.size() && stoi(all_two_digits[i + 1]) < 24)
            return all_two_digits[i + 1] + ":" + all_two_digits[0];

        return all_two_digits[0] + ":" + all_two_digits[0];
    }
};
