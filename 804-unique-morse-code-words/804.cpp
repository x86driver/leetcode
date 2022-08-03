class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };

        set<string> transform;
        for (string &word : words) {
            string s;
            for (char c : word) {
                string m = morse[c-'a'];
                s += m;
            }
            transform.insert(s);
        }

        return transform.size();
    }
};
