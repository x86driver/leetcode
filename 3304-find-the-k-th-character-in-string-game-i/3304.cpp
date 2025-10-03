class Solution {
public:
    char kthCharacter(int k) {
        string word = "ab";
        string generated = "b";
        while (word.size() < k) {
            int size = generated.size();
            for (int i = 0; i < size; ++i) {
                char ch = generated[i];
                char next = ch + 1;
                if (ch == 'z') {
                    next = 'a';
                }
                generated += next;
            }
            word += generated;
        }
        return word[k - 1];
    }
};
