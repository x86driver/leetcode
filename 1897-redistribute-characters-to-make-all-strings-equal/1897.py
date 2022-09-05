class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        table = Counter()
        for word in words:
            for w in word:
                table[w] += 1

        for key in table:
            if table[key] % len(words) != 0:
                return False

        return True
