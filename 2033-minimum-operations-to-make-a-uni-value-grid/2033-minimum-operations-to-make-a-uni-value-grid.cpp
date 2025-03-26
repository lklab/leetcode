class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;
        vector<int> arr(size);

        int base = grid[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((grid[i][j] - base) % x != 0) {
                    return -1;
                }

                arr[i * m + j] = grid[i][j];
            }
        }

        if (arr.size() == 1) {
            return 0;
        }

        sort(arr.begin(), arr.end());

        int median = arr[size / 2];
        int operations = 0;

        for (int val : arr) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};
