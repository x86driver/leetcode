class Solution {
private:
    bool isValidCode(const string& code) {
        if (code.empty()) {
            return false;
        }
        for (char c : code) {
            if (!isalpha(c) && !isdigit(c) && c != '_') {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> electronics, grocery, pharmacy, restaurant;
        for (int i = 0; i < code.size(); ++i) {
            if (isActive[i] && isValidCode(code[i])) {
                if (businessLine[i] == "electronics") {
                    electronics.push_back(code[i]);
                } else if (businessLine[i] == "grocery") {
                    grocery.push_back(code[i]);
                } else if (businessLine[i] == "pharmacy") {
                    pharmacy.push_back(code[i]);
                } else if (businessLine[i] == "restaurant") {
                    restaurant.push_back(code[i]);
                }
            }
        }
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());
        vector<string> ans = electronics;
        ans.insert(ans.end(), grocery.begin(), grocery.end());
        ans.insert(ans.end(), pharmacy.begin(), pharmacy.end());
        ans.insert(ans.end(), restaurant.begin(), restaurant.end());

        return ans;
    }
};
