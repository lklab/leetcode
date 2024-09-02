class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        n = len(chalk)
        for i in range(1, n) :
            chalk[i] += chalk[i-1]
        
        k %= chalk[n-1]

        l = 0
        r = n - 1

        while l < r :
            m = (l + r) // 2
            val = chalk[m]

            if val == k :
                return m + 1
            elif val < k :
                l = m + 1
            else :
                r = m

        return l
