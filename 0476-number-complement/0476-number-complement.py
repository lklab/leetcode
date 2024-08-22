class Solution:
    def findComplement(self, num: int) -> int:
        result = 0
        mask = 1

        while num > 0 :
            if num & 1 == 0 :
                result |= mask
            num >>= 1
            mask <<= 1

        return result
