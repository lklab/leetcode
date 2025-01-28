class Solution {
private:
    int dirs[5] = { -1, 0, 1, 0, -1 };
    int m = 0;
    int n = 0;

    int findAllFish(vector<vector<int>>& grid, int r, int c) {
        int count = grid[r][c];
        grid[r][c] = 0;

        for (int i = 0; i < 4; ++i) {
            int r2 = r + dirs[i];
            int c2 = c + dirs[i + 1];

            if (r2 >= 0 && r2 < m && c2 >= 0 && c2 < n && grid[r2][c2] > 0) {
                count += findAllFish(grid, r2, c2);
            }
        }

        return count;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    result = max(result, findAllFish(grid, i, j));
                }
            }
        }

        return result;
    }
};
