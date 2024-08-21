# source: https://leetcode.com/problems/strange-printer/solutions/3839612/python-beats-100-time-and-space/?envType=daily-question&envId=2024-08-21

class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        # Initialize diagonal elements
        for i in range(n):
            dp[i][i] = 1

        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = 1 + dp[i + 1][j]  # Printing s[i] separately

                for k in range(i + 1, j + 1):
                    if s[i] == s[k]:
                        if k == i + 1:
                            dp[i][j] = min(dp[i][j], dp[k][j])  # Merge s[i:k+1] into single character printing
                        else:
                            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j])  # Merge s[i:k+1] into single character printing

        return dp[0][n - 1]
