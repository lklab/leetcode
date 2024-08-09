class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        magicOrder = [2, 7, 6, 1, 8, 3, 4, 9]
        magicDict = {}
        for idx, n in enumerate(magicOrder) :
            magicDict[n] = idx
        order = [(-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)]

        def checkMagicSquares(i, j) :
            try :
                r = i + order[0][0]
                c = j + order[0][1]
                idx = magicDict[grid[r][c]]
            except KeyError :
                return False

            if idx % 2 != 0 :
                return False

            try :
                r = i + order[1][0]
                c = j + order[1][1]
                next = magicDict[grid[r][c]]

                if (idx + 1) % 8 == next :
                    dir = 1
                elif (idx - 1) % 8 == next :
                    dir = -1
                else :
                    return False

                idx = next

            except KeyError :
                return False

            for step in range(2, 8) :
                idx += dir
                idx %= 8
                expected = magicOrder[idx]

                r = i + order[step][0]
                c = j + order[step][1]
                if grid[r][c] != expected :
                    return False

            return True

        row = len(grid)
        col = len(grid[0])
        count = 0

        for i in range(1, row - 1) :
            for j in range(1, col - 1) :
                if grid[i][j] == 5 and checkMagicSquares(i, j) :
                    count += 1

        return count
