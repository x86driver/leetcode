class Solution {
private:
    void extractVersion(string version, vector<int>& result) {
        stringstream ss(version);
        while (ss.good()) {
            string substr;
            getline(ss, substr, '.');
            if (substr.size() > 1) {
                size_t i = 0;
                while (i < substr.size()) {
                    if (substr[i] != '0') {
                        break;
                    }
                    ++i;
                }
                if (i >= substr.size()) {
                    result.push_back(0);
                } else {
                    result.push_back(stoi(substr.substr(i)));
                }
            } else {
                result.push_back(stoi(substr));
            }
        }
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1, ver2;
        extractVersion(version1, ver1);
        extractVersion(version2, ver2);

        if (ver1.size() > ver2.size()) {
            int diff = ver1.size() - ver2.size();
            for (int i = 0; i < diff; ++i) {
                ver2.push_back(0);
            }
        } else if (ver2.size() > ver1.size()) {
            int diff = ver2.size() - ver1.size();
            for (int i = 0; i < diff; ++i) {
                ver1.push_back(0);
            }
        }

        for (int i = 0; i < ver1.size(); ++i) {
            if (ver1[i] > ver2[i]) {
                return 1;
            }
            if (ver1[i] < ver2[i]) {
                return -1;
            }
        }

        return 0;
    }
};
