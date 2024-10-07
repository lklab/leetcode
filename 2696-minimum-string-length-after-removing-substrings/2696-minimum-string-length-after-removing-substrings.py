class Solution:
    def minLength(self, s: str) -> int:
        n = len(s)
        result = n
        stack = []
        block = ord('E')

        for c in s :
            if not stack :
                stack.append(c)
            else :
                if ord(c) >= block :
                    stack.clear()
                    continue

                last = stack[-1]
                if last == 'A' and c == 'B' or last == 'C' and c == 'D' :
                    stack.pop()
                    result -= 2
                else :
                    stack.append(c)

        return result
