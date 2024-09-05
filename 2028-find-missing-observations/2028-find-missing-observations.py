class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        target = (len(rolls) + n) * mean - sum(rolls)

        if target > n * 6 :
            return []

        quotient = target // n
        remain = target % n

        if quotient <= 0 :
            return []

        result = [0] * n
        for i in range(n) :
            if i < remain :
                result[i] = quotient + 1
            else :
                result[i] = quotient

        return result
