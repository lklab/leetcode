class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        total = sum(piles)
        calculated = {}

        def dp(pre, idx, m) :
            current = 0
            score_max = 0

            if (idx, m) in calculated :
                return calculated[(idx, m)]

            for i in range(idx, min(idx + 2 * m, n)) :
                current += piles[i]
                x = i + 1 - idx
                score_op = dp(pre + current, i + 1, max(m, x))
                score_my = total - pre - score_op
                if score_my > score_max :
                    score_max = score_my

            calculated[(idx, m)] = score_max
            return score_max

        return dp(0, 0, 1)
