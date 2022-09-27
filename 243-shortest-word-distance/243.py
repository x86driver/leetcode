class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        table = {}
        for i in range(len(wordsDict)):
            word = wordsDict[i]
            if word in table:
                table[word].append(i)
            else:
                table[word] = [i]

        pos1 = table[word1]
        pos2 = table[word2]

        diff = [math.inf] * len(pos1)
        for i in range(len(pos1)):
            for j in range(len(pos2)):
                diff[i] = min(diff[i], abs(pos2[j]-pos1[i]))

        return min(diff)
