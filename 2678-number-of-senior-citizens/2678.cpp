class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (const string& person : details) {
            string age = person.substr(11, 2);
            if (stoi(age) > 60)
                ++count;
        }
        return count;
    }
};
