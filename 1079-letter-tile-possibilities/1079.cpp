class Solution {
private:
    set<string> s;
    //vector<string> s;
    vector<bool> used;
    string temp;
    void bt(string& tiles, int index, int k) {
        if (index >= tiles.size() || temp.size() == k) {
            s.insert(temp);
            return;
        }
        for (int i = 0; i < used.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                temp += tiles[i];
                bt(tiles, index + 1, k);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int count = 0;
        for (int i = 1; i <= tiles.size(); ++i) {
            used.clear();
            used.resize(tiles.size());
            s.clear();
            bt(tiles, 0, i);
            count += s.size();
        }
        return count;
    }
};
