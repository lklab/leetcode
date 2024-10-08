class Solution:
    def minSwaps(self, s: str) -> int:
        n = len(s)
        l = 0
        r = n - 1
        count = 0
        result = 0

        while l < r :
            if s[l] == '[' :
                count += 1
            else :
                count -= 1
            
            if count < 0 :
                while s[r] != '[' :
                    r -= 1
                count = 1
                result += 1
                r -= 1

            l += 1

        return result
