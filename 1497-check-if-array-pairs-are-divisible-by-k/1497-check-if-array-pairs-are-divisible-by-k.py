class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remains = [0] * k

        for num in arr :
            remains[num % k] += 1

        if remains[0] % 2 != 0 :
            return False

        if k % 2 == 0 and remains[k // 2] % 2 != 0 :
            return False

        for i in range(1, k // 2 + 1) :
            if remains[i] != remains[k - i] :
                return False

        return True
