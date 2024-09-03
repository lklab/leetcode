class Solution:
    def getLucky(self, s: str, k: int) -> int:
        lucky = 0

        for c in s :
            num = ord(c) - 96
            if num >= 10 :
                lucky *= 100
            else :
                lucky *= 10
            lucky += num

        while k > 0 :
            k -= 1
            newLucky = 0
            while lucky > 0 :
                newLucky += lucky % 10
                lucky //= 10
            lucky = newLucky

        return lucky
