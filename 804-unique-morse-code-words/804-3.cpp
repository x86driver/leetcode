class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for (const string& str : words) {
            string trans;
            for (char c : str) {
                trans += morse[c - 'a'];
            }
            s.insert(trans);
        }
        return s.size();
    }
};
