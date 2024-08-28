class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m = len(grid1)
        n = len(grid1[0])
        neighbors = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        islandId = 2
        subIslandCount = 0

        def dfs(x, y, id) :
            isSubIsland = grid1[x][y] == 1
            grid2[x][y] = id

            for neighbor in neighbors :
                x2 = x + neighbor[0]
                y2 = y + neighbor[1]

                if x2 >= 0 and x2 < m and y2 >= 0 and y2 < n and grid2[x2][y2] == 1 :
                    isSubIsland &= dfs(x2, y2, id)

            return isSubIsland

        for x in range(m) :
            for y in range(n) :
                if grid2[x][y] == 1 :
                    if dfs(x, y, islandId) :
                        subIslandCount += 1
                    islandId += 1

        return subIslandCount
