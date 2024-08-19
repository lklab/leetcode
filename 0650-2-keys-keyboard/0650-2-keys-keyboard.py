class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1 :
            return 0

        d = n // 2
        for i in range(d, 0, -1) :
            d = i
            if n % i == 0 :
                break

        # print(d)
        if d == 1 :
            return n
        else :
            return self.minSteps(d) + (n // d)
