class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        n  = rows * cols

        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        dirIndex = 0
        dir = dirs[dirIndex]

        r = rStart
        c = cStart
        result = [[r, c]]

        count = 1

        moveMax = 1
        moveCount = moveMax
        dirCount = 2

        while count < n :
            r += dir[0]
            c += dir[1]

            moveCount -= 1
            if moveCount <= 0 :
                dirCount -= 1
                if dirCount <= 0 :
                    moveMax += 1
                    dirCount = 2
                moveCount = moveMax

                dirIndex += 1
                dirIndex %= 4
                dir = dirs[dirIndex]

            if r >= 0 and r < rows and c >= 0 and c < cols :
                result.append([r, c])
                count += 1

        return result
