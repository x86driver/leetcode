class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int count = 1;
        depth[startGene] = 0;
        //visit[startGene] = true;
        vector<string> mutations = validMutation(bank, startGene);

        cout << "Fist valid: ";
        for (auto i : mutations)
            cout << i << " ";
        cout << endl;

        queue<pair<string, int>> q;
        for (string& s : mutations) {
            q.push({s, 1});
            visit[s] = true;
            cout << "push " << s << endl;
        }

        while (!q.empty()) {
            string gene = q.front().first;
            int currDepth = q.front().second;
            q.pop();

            if (gene == endGene) {
                cout << "Found at front " << gene << " depth: " << currDepth << endl;
                return currDepth;
            }

            vector<string> m = validMutation(bank, gene);
            for (string& s : m) {
                if (s == endGene) {
                    cout << "Found " << s << " depth: " << currDepth + 1 << endl;
                    return currDepth + 1;
                }
                if (!visit[s]) {
                    q.push({s, currDepth + 1});
                    visit[s] = true;
                    cout << "push " << s << " depth: " << currDepth + 1 << endl;
                }
            }
        }

        if (depth.find(endGene) == depth.end())
            return -1;
        else
            return depth[endGene];
    }

private:
    unordered_map<string, int> depth;
    unordered_map<string, bool> visit;
    vector<string> validMutation(vector<string>& bank, string gene) {
        vector<string> ret;
        //visit.clear();
        for (int i = 0; i < bank.size(); ++i) {
            int diff = 8;
            for (int j = 0; j < gene.size(); ++j) {
                if (bank[i][j] == gene[j])
                    --diff;
            }
            if (diff == 1)// && visit[bank[i]] > 0)
                ret.push_back(bank[i]);
        }

        return ret;
    }
};
