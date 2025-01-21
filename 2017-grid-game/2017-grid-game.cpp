class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long sum0 = 0;
        long long sum1 = 0;

        for (int i = 1; i < n; ++i) {
            sum0 += grid[0][i];
        }

        long long point2 = sum0;

        for (int i = 1; i < n; ++i) {
            sum0 -= grid[0][i];
            sum1 += grid[1][i - 1];

            point2 = min(point2, max(sum0, sum1));
        }

        return point2;
    }
};
