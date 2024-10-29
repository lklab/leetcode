class Solution
{
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];

        for (int i = 0; i < m; ++i)
        {
            dp[i][n-1] = 0;
        }

        for (int i = n - 1; i >= 1; --i)
        {
            int x = i - 1;
            for (int j = 0; j < m; ++j)
            {
                int count = 0;

                if ((j >= 1 && grid[j-1][i] > grid[j][x]))
                {
                    count = dp[j-1][i] + 1;
                }
                if (grid[j][i] > grid[j][x])
                {
                    count = max(count, dp[j][i] + 1);
                }
                if (j <= m-2 && grid[j+1][i] > grid[j][x])
                {
                    count = max(count, dp[j+1][i] + 1);
                }

                dp[j][x] = count;
            }
        }

        int result = 0;
        for (int i = 0; i < m; ++i)
        {
            result = max(result, dp[i][0]);
        }

        return result;
    }
};
