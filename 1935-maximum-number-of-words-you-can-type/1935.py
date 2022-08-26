class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        count = 0
        table = set(brokenLetters)

        words = text.split(' ')
        for word in words:
            for w in word:
                if w in table:
                    count += 1
                    break

        return len(words) - count
