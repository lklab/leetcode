class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n = len(s1)

        s1Freq = [0] * 26
        for c in s1 :
            s1Freq[ord(c) - 97] += 1

        s2Freq = None

        for i, c in enumerate(s2) :
            code = ord(c) - 97

            if s1Freq[code] > 0 :
                if s2Freq == None :
                    s2Freq = s1Freq.copy()
                    s = i

                s2Freq[code] -= 1

                while s2Freq[code] < 0 :
                    s2Freq[ord(s2[s]) - 97] += 1
                    s += 1

                if i - s == n - 1 :
                    return True

            elif s2Freq != None :
                s2Freq = None

        return False
