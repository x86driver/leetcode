class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        text1 = " " + text1
        text2 = " " + text2

        dp = [[0] * len(text1) for _ in range(len(text2))]

        for t in range(1, len(text2)):
            s = text2[t]
            for i in range(1, len(text1)):
                if text1[i] == s:
                    dp[t][i] = dp[t-1][i-1] + 1
                else:
                    dp[t][i] = max(dp[t-1][i], dp[t][i-1])

        return dp[-1][-1]
