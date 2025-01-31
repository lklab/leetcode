class Solution {
private:
    int dirs[5] = { -1, 0, 1, 0, -1 };
    int n = 0;
    int dfs(vector<vector<int>>& grid, int x, int y, int islandId, vector<pair<int, int>>& boundary) {
        grid[x][y] = islandId;
        int count = 1;
        bool isBoundary = false;

        for (int i = 0; i < 4; ++i) {
            int x2 = x + dirs[i];
            int y2 = y + dirs[i + 1];

            if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n) {
                if (grid[x2][y2] == 0) {
                    isBoundary = true;
                } else if (grid[x2][y2] == 1) {
                    count += dfs(grid, x2, y2, islandId, boundary);
                }
            }
        }

        if (isBoundary) {
            boundary.emplace_back(x, y);
        }

        return count;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> islandSizes;
        vector<vector<pair<int, int>>> boundaries;
        int islandId = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    boundaries.emplace_back();
                    int size = dfs(grid, i, j, islandId, boundaries[-islandId-1]);
                    islandSizes.push_back(size);
                    --islandId;
                }
            }
        }

        int result = 0;
        int islandCount = islandSizes.size();

        for (int i = 0; i < islandCount; ++i) {
            int size = islandSizes[i];
            int islandId = -i-1;
            result = max(result, size);

            for (auto [x, y] : boundaries[i]) {
                for (int j = 0; j < 4; ++j) {
                    int x2 = x + dirs[j];
                    int y2 = y + dirs[j + 1];

                    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && grid[x2][y2] == 0) {
                        int newSize = size + 1;
                        vector<bool> isUnion(islandCount, false);

                        for (int k = 0; k < 4; ++k) {
                            int x3 = x2 + dirs[k];
                            int y3 = y2 + dirs[k + 1];

                            if (x3 >= 0 && x3 < n && y3 >= 0 && y3 < n && grid[x3][y3] < islandId && !isUnion[-grid[x3][y3]-1]) {
                                isUnion[-grid[x3][y3]-1] = true;
                                newSize += islandSizes[-grid[x3][y3]-1];
                            }
                        }

                        result = max(result, newSize);
                    }
                }
            }
        }

        return max(result, 1);
    }
};
