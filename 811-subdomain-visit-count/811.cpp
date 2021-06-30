#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> tables;
        for (auto &s : cpdomains) {
            pair<string, int> ret = split(s);
            string &domain = ret.first;
            int count = ret.second;
            tables[domain] += count;
            for (size_t i = 0; i < domain.length(); ++i) {
                if (domain[i] == '.') {
                    string sub = domain.substr(i+1, string::npos);
                    tables[sub] += count;
                }
            }
        }
        for (auto &t : tables) {
            ans.push_back(std::to_string(t.second) + " " + t.first);
        }
        return ans;
    }

private:
  pair<string, int> split(string &s) {
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                int count = stoi(s.substr(0, i));
                string domain = s.substr(i+1, string::npos);
                return make_pair(domain, count);
            }
        }
        return make_pair("", 0);
    }
};

int main() {
    Solution s;
    //    vector<string> input = {"9001 discuss.leetcode.com"};
    vector<string> input = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> answer = s.subdomainVisits(input);
    for (auto &a : answer) {
        cout << a << endl;
    }
    return 0;
}
