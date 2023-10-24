bool isVowel(const char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int vowelStrings(char ** words, int wordsSize, int left, int right){
    int count = 0;
    for (int i = left; i <= right; ++i) {
        char first = words[i][0];
        char last = words[i][strlen(words[i]) - 1];
        if (isVowel(first) && isVowel(last))
            ++count;
    }
    return count;
}
