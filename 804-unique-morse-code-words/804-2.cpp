class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for (const string& word : words) {
            string output;
            for (const char c : word)
                output += morse[c - 'a'];
            s.insert(output);
        }
        return s.size();
    }
};
